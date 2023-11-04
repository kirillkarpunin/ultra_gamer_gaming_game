#include "Game.h"
#include "../../include/getch/getch.h"


Game::Game() {
    player = new Player;
    playground = new Playground;
    player_manager = new PlayerManager(*player, *playground);

    renderer = new Renderer();
    map_generator = new MapGenerator();

    playground_size = playground->get_size();
    game_is_running = true;
    saved_progress = false;
    level = 0;
}

Game::~Game() {
    delete renderer;
    delete map_generator;

    delete playground;
    delete player_manager;
    delete player;
}

void Game::create_new_level() {
    delete playground;
    delete player_manager;

    if (level == 0 || player_manager->is_defeated()) {
        delete player;
        player = new Player;
    }
    playground = new Playground(playground_size.first, playground_size.second);
    player_manager = new PlayerManager(*player, *playground);

    map_generator->generate(*playground);
    player_manager->set_position(playground->get_entrance_point());

    level++;
    saved_progress = true;
}

void Game::game_loop() {

    if (!saved_progress) create_new_level();

    game_is_running = true;
    while(game_is_running && !player_manager->is_defeated() && !player_manager->is_on_exit()) {

        renderer->terminal_clear();
        renderer->print_level(level);
        renderer->print_map(*playground, *player_manager);
        renderer->print_player_info(*player_manager);

        int ch = getch();

        switch (ch)
        {
            case 27:
                pause_menu();
                if (!saved_progress) create_new_level();
                break;

            case 'w':
                player_manager->move(up);
                break;
            case 'a':
                player_manager->move(left);
                break;
            case 's':
                player_manager->move(down);
                break;
            case 'd':
                player_manager->move(right);
                break;
            case ' ':
                player_manager->move(none);
                break;

        }
    }
    renderer->terminal_clear();

    if (player_manager->is_defeated()){
        saved_progress = false;
        defeat_menu();
    }
    else if (player_manager->is_on_exit()){
        saved_progress = false;
        victory_menu();
    }
}

void Game::main_menu() {
    Menu m_menu({
                    {"play", play_game},
                    {"settings", settings},
                    {"exit", exit_game}
            });

    while(m_menu.is_active()){
        renderer->terminal_clear();
        renderer->print_logo();
        renderer->print_menu(m_menu);

        int ch = getch();

        switch (ch)
        {
            case 27:
                m_menu.close();
                break;

            case 'w':
                m_menu.option_up();
                break;
            case 's':
                m_menu.option_down();
                break;
            case ' ':
                switch (m_menu.choose_option()) {
                    case exit_game:
                        m_menu.close();
                        break;
                    case play_game:
                        game_loop();
                        break;
                    case settings:
                        break;
                }
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
        renderer->print_logo();
        renderer->print_menu(p_menu);

        int ch = getch();

        switch (ch)
        {
            case 27:
                p_menu.close();
                break;

            case 'w':
                p_menu.option_up();
                break;
            case 's':
                p_menu.option_down();
                break;
            case ' ':
                switch (p_menu.choose_option()) {
                    case return_main_menu:
                        p_menu.close();
                        game_is_running = false;
                        break;
                    case new_game:
                        level = 0;
                        saved_progress = false;
                        p_menu.close();
                        break;
                    case resume:
                        p_menu.close();
                        break;
                    case settings:
                        break;
                }
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
        renderer->victory_end(level);
        renderer->print_menu(v_menu);

        int ch = getch();

        switch (ch) {
            case 'w':
                v_menu.option_up();
                break;
            case 's':
                v_menu.option_down();
                break;
            case ' ':
                switch (v_menu.choose_option()) {
                    case return_main_menu:
                        v_menu.close();
                        game_is_running = false;
                        break;
                    case next_level:
                        v_menu.close();
                        game_loop();
                        break;
                }
        }
    }
}

void Game::defeat_menu() {
    int tmp = level;
    level = 0;

    Menu d_menu({
                        {"try again", new_game},
                        {"main menu", return_main_menu}
                });

    while(d_menu.is_active()) {
        renderer->terminal_clear();
        renderer->defeat_end(tmp);
        renderer->print_menu(d_menu);

        int ch = getch();

        switch (ch) {
            case 'w':
                d_menu.option_up();
                break;
            case 's':
                d_menu.option_down();
                break;
            case ' ':
                switch (d_menu.choose_option()) {
                    case return_main_menu:
                        d_menu.close();
                        game_is_running = false;
                        break;
                    case new_game:
                        d_menu.close();
                        game_loop();
                        break;
                }
        }
    }
}
