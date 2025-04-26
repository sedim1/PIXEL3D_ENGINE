///SDL TEMPLATE PROGRAM
#include "Engine.h"

//Main functions
bool Init();
void Update();
void End();
void Display();
void HandleEvents();


//Global variables to be accesed througout all c files
extern Keyboard key;

//window to render
extern SDL_Window* window;
//The surface contained by the window
extern SDL_Renderer* renderer;
bool isRunning = true;


int main(int argc, char* argv[]){
	if(!Init())
		return -1;
	Update();
	End();
	return 0;
}

bool Init(){
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() ); return false;
	}

	//Create window
        window = SDL_CreateWindow("SDL",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); return false;
        }
	//Get window surface
        renderer = SDL_CreateRenderer(window,-1,0);
        if( renderer == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() ); return false;
        }

	return true;
}


void Update(){
	while(isRunning){
		HandleEvents();
		//Game logic goes here
		//Start rendering after processing the game logic
		Display();
	}
}

void Display(){
	SDL_SetRenderDrawColor(renderer,0,0,0,255); //Clear screen color
	SDL_RenderClear(renderer); //Clear 
	//Rendering logic goes here
	//renderTest();
	renderCubeTest();
	SDL_RenderPresent(renderer); //Render the final image final image
}

void End(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	printf("Exiting\n");
}

void HandleEvents(){
	SDL_Event e;
	SDL_PollEvent(&e);
	switch(e.type){
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch(e.key.keysym.sym){
				case SDLK_ESCAPE:
					isRunning = false;
					break;
				case SDLK_w:
					key.w = 1;
					break;
				case SDLK_s:
					key.s = 1;
					break;
				case SDLK_a:
					key.a = 1;
					break;
				case SDLK_d:
					key.d = 1;
					break;
				case SDLK_i:
					key.i = 1;
					break;
				case SDLK_k:
					key.k = 1;
					break;
				case SDLK_j:
					key.j = 1;
					break;
				case SDLK_l:
					key.l = 1;
					break;
				case SDLK_LSHIFT:
					key.shift = 1;
					break;
				default:
					break;
			}
			break;
		 case SDL_KEYUP:
                        switch(e.key.keysym.sym){
                                case SDLK_ESCAPE:
                                        isRunning = false;
                                        break;
                                case SDLK_w:
                                        key.w = 0;
                                        break;
                                case SDLK_s:
                                        key.s = 0;
                                        break;
                                case SDLK_a:
                                        key.a = 0;
                                        break;
                                case SDLK_d:
                                        key.d = 0;
                                        break;
				case SDLK_i: 
                                        key.i = 0;
                                        break;
                                case SDLK_k:
                                        key.k = 0;
                                        break;
                                case SDLK_j:
                                        key.j = 0;
                                        break;
                                case SDLK_l:
                                        key.l = 0;
                                        break;
                                case SDLK_LSHIFT:
                                        key.shift = 0;
                                        break;
                                default:
                                        break;
                        }
                        break;
		default:
			break;
	}
}





