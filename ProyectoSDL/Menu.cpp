#include "Menu.h"

Menu::Menu(SDL_Renderer* renderer, int screenWidth, int screenHeight)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight) {
}

Menu::~Menu() {}

bool Menu::showStartScreen() {
    bool inMenu = true;
    SDL_Event event;

    // Fondo de la pantalla de inicio
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fondo negro
    SDL_RenderClear(renderer);

    renderStartScreen();  // Renderizar la pantalla de inicio

    SDL_RenderPresent(renderer);

    while (inMenu) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;  // Salir del juego
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_RETURN:  // Si se presiona Enter, empieza el juego
                    return true;  // Iniciar el juego
                case SDLK_ESCAPE:  // Si se presiona Escape, cierra el juego
                    return false;  // Salir del juego
                default:
                    break;
                }
            }
        }
    }
    return false;
}

bool Menu::showEndScreen() {
    bool inEndMenu = true;
    SDL_Event event;

    // Fondo de la pantalla de fin del juego
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fondo negro
    SDL_RenderClear(renderer);

    renderEndScreen();  // Renderizar la pantalla de fin

    SDL_RenderPresent(renderer);

    while (inEndMenu) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                return false;  // Salir del juego
            }

            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_RETURN:  // Si se presiona Enter, reinicia el juego
                    return true;  // Reiniciar el juego
                case SDLK_ESCAPE:  // Si se presiona Escape, cierra el juego
                    return false;  // Salir del juego
                default:
                    break;
                }
            }
        }
    }
    return false;
}

void Menu::renderStartScreen() {
    
    // Fondo de la pantalla de inicio
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Fondo negro
    SDL_RenderClear(renderer);
    
    // Cuadro verde para la opción "Jugar"
    SDL_Rect greenBox = { screenWidth / 3, screenHeight / 3, 200, 50 };  // (x, y, width, height)
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);  // Verde
    SDL_RenderFillRect(renderer, &greenBox);
    
    // Cuadro rojo para la opción "Salir"
    SDL_Rect redBox = { screenWidth / 3, screenHeight / 2, 200, 50 };  // (x, y, width, height)
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Rojo
    SDL_RenderFillRect(renderer, &redBox);
    
    // Puedes agregar más detalles aquí si quieres, como texto encima de los cuadros
    // (necesitarías una forma de renderizar texto en SDL, como usar SDL_ttf)
    
    SDL_RenderPresent(renderer);
    

 }

void Menu::renderEndScreen() {
    // Aquí renderizas lo que aparece cuando el jugador pierde o decide salir.
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // Rojo (para indicar fin)
    // De nuevo, mostrarías algo como "Juego terminado" y las opciones para reiniciar o salir.
}
