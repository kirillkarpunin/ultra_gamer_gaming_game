#include "Game.h"
#include "../../include/getch/getch.h"


Game::Game() {
    player = new Player;

    printer = new Printer();
    renderer = new Renderer();

    config = new Config("../config.txt");

    level = new Level(player);
    
    playground_size = level->playground->get_size();
    game_is_running = true;
    saved_progress = false;
    level_n = 0;
}

Game::~Game() {
    delete config;

    delete printer;
    delete renderer;

    delete level;
    delete player;
}

void Game::create_new_level() {
    if (level_n == 0) {
        delete player;
        player = new Player;
    }

    level->new_level(player, playground_size);

    level_n++;
    saved_progress = true;
    playground_size = level->playground->get_size();
}

void Game::game_loop() {

    if (!saved_progress) create_new_level();

    game_is_running = true;
    while(game_is_running && !level->player_manager->is_defeated() && !level->player_manager->is_on_exit()) {

        renderer->terminal_clear();
        renderer->print_level(level_n);
        renderer->render_map(*level->playground, *level->player_manager);
        renderer->print_player_info(*level->player_manager);

        int ch = getch();

        switch (config->pressed_key(ch))
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
    renderer->terminal_clear();

    if (level->player_manager->is_defeated()){
        saved_progress = false;
        defeat_menu();
    }
    else if (level->player_manager->is_on_exit()){
        saved_progress = false;
        victory_menu();
    }
}

void Game::main_menu() {

    if (!config->is_valid()){
        printer->print_invalid_config();
        return;
    }

    Menu m_menu({
                    {"play", play_game},
                    {"settings", settings},
                    {"exit", exit_game},
            });

    while(m_menu.is_active()){
        renderer->terminal_clear();
        printer->print_logo();
        renderer->print_menu(m_menu);

        int ch = getch();

        switch (m_menu.update(config->pressed_key(ch)))
        {
            case exit_game:
                m_menu.close();
                break;
            case play_game:
                game_loop();
                break;
            case settings:
                settings_menu();
                break;
            case nothing:
            default:
                break;
        }
    }
}

void Game::pause_menu() {
    Menu p_menu({
                        {"resume", resume},
                        {"new game", new_game},
                        {"settings", settings},
                        {"return to main menu", return_main_menu},
    });

    while(p_menu.is_active()){
        renderer->terminal_clear();
        printer->print_pause_label();
        renderer->print_menu(p_menu);

        int ch = getch();

        switch (p_menu.update(config->pressed_key(ch)))
        {
            case return_main_menu:
                p_menu.close();
                game_is_running = false;
                break;
            case new_game:
                level_n = 0;
                saved_progress = false;
                p_menu.close();
                break;
            case resume:
                p_menu.close();
                break;
            case settings:
                settings_menu();
                break;
            case nothing:
            default:
                break;
        }
    }
}

void Game::victory_menu() {
    Menu v_menu({
                        {"next level", next_level},
                        {"main menu", return_main_menu}
    });

    while(v_menu.is_active()) {
        renderer->terminal_clear();
        renderer->victory_end(level_n);
        renderer->print_menu(v_menu);

        int ch = getch();

        switch (v_menu.update(config->pressed_key(ch)))
        {
            case return_main_menu:
                v_menu.close();
                game_is_running = false;
                break;
            case next_level:
                v_menu.close();
                game_loop();
                break;
            case nothing:
            default:
                break;
        }
    }
}

void Game::defeat_menu() {
    int tmp = level_n;
    level_n = 0;

    Menu d_menu({
                        {"try again", new_game},
                        {"main menu", return_main_menu}
                });

    while(d_menu.is_active()) {
        renderer->terminal_clear();
        renderer->defeat_end(tmp);
        renderer->print_menu(d_menu);

        int ch = getch();

        switch (d_menu.update(config->pressed_key(ch)))
        {
            case return_main_menu:
                d_menu.close();
                game_is_running = false;
                break;
            case new_game:
                d_menu.close();
                game_loop();
                break;
            case nothing:
            default:
                break;
        }
    }
}

void Game::settings_menu() {
    Menu s_menu({
                        {"change field size", change_size},
                        {"back", resume}
    });

    while(s_menu.is_active()){
        renderer->terminal_clear();
        printer->print_settings_label();
        renderer->print_menu(s_menu);

        int ch = getch();

        switch (s_menu.update(config->pressed_key(ch)))
        {
            case resume:
                s_menu.close();
                break;
            case change_size:
                new_size();
                break;
            case nothing:
            default:
                break;
        }
    }
}

void Game::new_size() {
    renderer->terminal_clear();

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

