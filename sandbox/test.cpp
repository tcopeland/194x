#include "SDL.h"
 
int main(int argc, char* argv[])
{
		SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO);

    /* An SDL_Event struct */
    SDL_Event event;
 
    /* A bool to check if the program has exited */
    int quit = 0;
 
    /* While the program is running */
    while (!quit)
    {
        /* Check for new events */
        while(SDL_PollEvent(&event))
        {
					printf("got event\n");
            /* If a quit event has been sent */
            if (event.type == SDL_QUIT)
            {
                /* Quit the application */
                quit = 1;
            }
							
						printf("some event\n");
             
            /* If a button on the mouse is pressed. */
            if (event.type == SDL_MOUSEBUTTONDOWN)
            {
                /* If the left button was pressed. */
                if (event.button.button == SDL_BUTTON_LEFT)
                    /* Quit the application */
                    quit = 1;
            }
        }
    }
}