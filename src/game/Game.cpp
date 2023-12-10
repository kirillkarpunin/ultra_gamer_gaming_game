#include "Game.h"

Game::Game() {
    player = new Player;
    level = new Level(player);

    menu_handler = new MenuHandler();
    input_handler = new InputHandler("../config.txt");

    updater = new Updater();
    level->player_manager->add_observer(updater);
    menu_handler->set_observer(updater);

    playground_size = level->playground->get_size();
    game_is_running = true;
    saved_progress = false;
    restart = true;
}

Game::~Game() {
    delete input_handler;
    delete menu_handler;
    delete updater;

    delete level;
    delete player;
}


void Game::init() {
    if (!input_handler->is_valid()){
        std::cout << "Invalid config";
        return;
    }

    logger_menu();
    main_menu();
}

void Game::create_new_level() {
    if (restart) {
        delete player;
        player = new Player;
        restart = false;
        level->player_manager->reset_passed_levels();

        auto ngm = new NewGameMessage;
        updater->add_message(ngm);
    }

    level->new_level(player, playground_size);
    level->player_manager->add_observer(updater);

    saved_progress = true;
    playground_size = level->playground->get_size();

    auto nlm = new NewLevelMessage(playground_size, level->player_manager->get_position(), level->player_manager->get_passed_levels());
    updater->add_message(nlm);
}

void Game::game_loop() {
    if (!saved_progress) create_new_level();

    updater->update_game_frame(level->playground, level->player_manager);
    updater->update_logs();

    game_is_running = true;
    while(game_is_running && !level->player_manager->is_defeated() && !level->player_manager->is_on_exit()) {

        std::string command;
        int ch = input_handler->scan_char();

        switch (input_handler->get_key(ch))
        {
            case up_key:
                level->player_manager->move(up);
                command = level->player_manager->dir_to_str(up);
                break;
            case left_key:
                level->player_manager->move(left);
                command = level->player_manager->dir_to_str(left);
                break;
            case down_key:
                level->player_manager->move(down);
                command = level->player_manager->dir_to_str(down);
                break;
            case right_key:
                level->player_manager->move(right);
                command = level->player_manager->dir_to_str(right);
                break;
            case esc_key:
                pause_menu();
                if (!saved_progress) create_new_level();
                level->player_manager->move(none);
                break;
            case wait_key:
                level->player_manager->move(none);
                command = level->player_manager->dir_to_str(none);
                break;
            default:
                break;
        }

        if (!command.empty()){
            auto kcs = new KeyWithCommandMessage(ch, command);
            updater->add_message(kcs);
        }
        else{
            auto kwcs = new KeyWithoutCommandMessage(ch);
            updater->add_message(kwcs);
        }

        updater->check_updates();
    }

    if (level->player_manager->is_defeated()){
        auto dm = new DefeatMessage(level->player_manager->get_position());
        updater->add_message(dm);

        restart = true;
        saved_progress = false;
        game_is_running = false;

        defeat_menu();
    }
    else if (level->player_manager->is_on_exit()){
        auto vm = new VictoryMessage(level->player_manager->get_health(), level->player_manager->get_armor(), level->player_manager->get_damage(), level->player_manager->get_bombs());
        updater->add_message(vm);

        saved_progress = false;
        game_is_running = false;

        victory_menu();
    }
}

void Game::main_menu() {
    MainMenu mm;

    while (mm.is_active())
    {
        menu_options res = menu_handler->run_menu(this, &mm);

        switch (res) {
            case exit_game:
                mm.close();
                return;
            case settings:
                settings_menu();
                break;
            case play_game:
                game_loop();
                break;
            default:
                break;
        }
    }
}

void Game::settings_menu() {
    SettingsMenu sm;

    while (sm.is_active())
    {
        menu_options res = menu_handler->run_menu(this, &sm);

        switch (res) {
            case resume:
                sm.close();
                break;
            case change_size:
                new_size();
                break;
            default:
                break;
        }
    }
}

void Game::pause_menu() {
    PauseMenu pm;

    while (pm.is_active())
    {
        menu_options res = menu_handler->run_menu(this, &pm);

        switch (res) {
            case return_main_menu:
                pm.close();
                game_is_running = false;
                break;
            case new_game:
                restart = true;
                saved_progress = false;
                pm.close();
                break;
            case resume:
                pm.close();
                break;
            case settings:
                settings_menu();
                break;
            default:
                break;
        }
    }
}

void Game::defeat_menu() {
    DefeatMenu dm;

    while (dm.is_active())
    {
        menu_options res = menu_handler->run_menu(this, &dm);

        switch (res) {
            case new_game:
                dm.close();
                game_loop();
                break;
            case resume:
            case return_main_menu:
                dm.close();
                break;
            default:
                break;
        }
    }
}

void Game::victory_menu() {
    VictoryMenu vm;

    while (vm.is_active())
    {
        menu_options res = menu_handler->run_menu(this, &vm);

        switch (res) {
            case play_game:
                vm.close();
                game_loop();
                break;
            case resume:
            case return_main_menu:
                vm.close();
                break;
            default:
                break;
        }
    }
}

void Game::logger_menu() {
    LoggerMenu lm;

    while (lm.is_active())
    {
        menu_options res = menu_handler->run_menu(this, &lm);

        switch (res) {
            case console:
            {
                lm.close();
                auto console_appender = new ConsoleAppender;
                updater->add_to_logger(console_appender);
                break;
            }
            case console_file:
            {
                lm.close();
                auto console_appender = new ConsoleAppender;
                updater->add_to_logger(console_appender);
                auto file_appender = new FileAppender("../log.txt");
                updater->add_to_logger(file_appender);
                break;
            }
            case file:
            {
                lm.close();
                auto file_appender = new FileAppender("../log.txt");
                updater->add_to_logger(file_appender);
                break;
            }
            default:
                break;
        }
    }

}

void Game::new_size() {
    system("clear");

    int height, width;
    std::string input;

    std::cout << "\nCurrent size: " << playground_size.first << " x " << playground_size.second;

    std::cout << "\n\n\tEnter new size:\n"
                 "Width: ";
    std::getline(std::cin, input);
    try {
        width = std::stoi(input, nullptr, 10);
    }
    catch (std::exception& err){
        return;
    }

    std::cout << "Height: ";
    std::getline(std::cin, input);
    try {
        height = std::stoi(input, nullptr, 10);
    }
    catch (std::exception& err){
        return;
    }

    playground_size.first = width;
    playground_size.second = height;
}
