#include "Game.h"

Game::Game() {
    player = new Player;
    level = new Level(player);

    menu_handler = new MenuHandler();
    renderer = new Renderer();
    input_handler = new InputHandler("../config.txt");

    playground_size = level->playground->get_size();
    game_is_running = true;
    saved_progress = false;
    restart = false;
}

Game::~Game() {
    delete input_handler;
    delete menu_handler;
    delete renderer;

    delete level;
    delete player;
}

void Game::create_new_level() {
    if (restart) {
        delete player;
        player = new Player;
        restart = false;
    }

    level->new_level(player, playground_size);

    saved_progress = true;
    playground_size = level->playground->get_size();
}

void Game::game_loop() {

    if (!saved_progress) create_new_level();

    game_is_running = true;
    while(game_is_running && !level->player_manager->is_defeated() && !level->player_manager->is_on_exit()) {

        renderer->terminal_clear();
        renderer->render_map(*level->playground, *level->player_manager);
        renderer->print_player_info(*level->player_manager);

        switch (input_handler->get_key())
        {
            case esc_key:
                pause_menu();
                if (!saved_progress) create_new_level();
                break;

            case up_key:
                level->player_manager->move(up);
                break;
            case left_key:
                level->player_manager->move(left);
                break;
            case down_key:
                level->player_manager->move(down);
                break;
            case right_key:
                level->player_manager->move(right);
                break;
            case wait_key:
                level->player_manager->move(none);
                break;
            default:
                break;
        }
    }

    if (level->player_manager->is_defeated()){
        defeat_menu();
    }
    else if (level->player_manager->is_on_exit()){
        victory_menu();
    }
}

void Game::main_menu() {

    if (!input_handler->is_valid())
        return;

    MainMenu mm;
    menu_options res = menu_handler->run_menu(this, &mm);

    switch (res) {
        case resume:
            main_menu();
            break;
        case exit_game:
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

void Game::settings_menu() {
    SettingsMenu sm;
    menu_options res = menu_handler->run_menu(this, &sm);

    switch (res) {
        case resume:
            main_menu();
            break;
        case change_size:
            new_size();
            settings_menu();
            break;
        default:
            break;
    }
}

void Game::pause_menu() {
    PauseMenu pm;
    menu_options res = menu_handler->run_menu(this, &pm);

    switch (res) {
            case return_main_menu:
                game_is_running = false;
                pm.close();
                main_menu();
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

void Game::defeat_menu() {
    restart = true;
    saved_progress = false;
    game_is_running = false;

    DefeatMenu dm;
    menu_options res = menu_handler->run_menu(this, &dm);

    switch (res) {
        case new_game:
            dm.close();
            game_loop();
            break;
        case resume:
        case return_main_menu:
            dm.close();
            main_menu();
            break;
        default:
            break;
    }
}

void Game::victory_menu() {
    saved_progress = false;
    game_is_running = false;

    VictoryMenu vm;
    menu_options res = menu_handler->run_menu(this, &vm);

    switch (res) {
        case play_game:
            vm.close();
            game_loop();
            break;
        case resume:
        case return_main_menu:
            main_menu();
            vm.close();
            break;
        default:
            break;
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
