#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <c++/iostream>

bool firsttime=true;
//   Tab names
constexpr int CLOSE_BUTTON=1;
constexpr int WINDOW_BUTTON=2;
constexpr int MINIMIZED_BUTTON=3;
constexpr int FILE_BUTTON=4;
constexpr int EDIT_BUTTON=5;
constexpr int SETTING_BUTTON=6;
// Button names
constexpr int TAB_GENERAL=1;

// structs
struct AppState{
    bool endProgram=false;
    bool fullScreen=false;
    int W,H,X,Y;
    int LastW,LastH;

    int FULL_SCREEN_W,FULL_SCREEN_H;
    SDL_Rect AVAILABLE_SCREEN;

    SDL_Renderer *renderer;
    SDL_Window *window;
};
struct MouseState{
    int x=0,y=0;

    bool rightDown=false;          // right click down in x0,y0
    bool rightPressed=false;       // right click hold from click down in x0,y0 until click up (can be in x0,y0 or not)
    bool rightUp=false;            // right click up

    bool leftDown=false;
    bool leftPressed=false;
    bool leftUp=false;
};
struct ButtonRect{
    int ID;
    SDL_Rect rect;
    SDL_Rect srcRect;

    bool onButton=false;
    bool rightClick=false;
    bool leftClick=false;
    bool rightPressed=false;
    bool leftPressed=false;


    bool active=true;

};
struct AllTabButtons{
    int ID;
    bool active;
    std::vector<ButtonRect> buttons;
};
struct KeyboardButton{
    bool keyUp[SDL_NUM_SCANCODES]={};       // this frame keyup ?
    bool pressed[SDL_NUM_SCANCODES]={};     // press right now ?
    bool keyDown[SDL_NUM_SCANCODES]={};     // this frame keydown ?
};
struct ThemeGeneralTab{
    SDL_Color mainBackground;

    SDL_Color closeButton;
    SDL_Color closeButtonMouse;
    SDL_Color windowButton;
    SDL_Color windowButtonMouse;
    SDL_Color minimizeButton;
    SDL_Color minimizeButtonMouse;
    SDL_Color top ={138,85,215,225};
};
struct Theme{
    ThemeGeneralTab general;
};
struct TabTexture {
    SDL_Texture* general= nullptr;
};
//---------
struct ButtonTextures{
    SDL_Texture* setting = nullptr;
    SDL_Texture* file = nullptr;
    SDL_Texture* flesh = nullptr;

};



// bool function
bool isMouseInRect(MouseState &mouse,SDL_Rect &rect);

// reset function
// در ابتدای هر فریم bool های لازم را ریست میدهد به دیفالت
void resetKeyboardButtons(KeyboardButton &key);
void resetButtonRect(std:: vector<AllTabButtons> &tab);
void resetMouseState(MouseState &mouse);

// update function
// با گرفتن هر ایونت اپدیت میکند
void updateKeyboardButtons(KeyboardButton &key,SDL_Event &e);
void updateMouseState(MouseState &mouse, SDL_Event &e);
void updateButtonRectAndMouseState(MouseState &mouse,std:: vector<AllTabButtons> &tab,SDL_Event &e);

// Action function
// عملیات مربوط را در هر فریم انجام میدهد با توجه به توابع مربوط به دکمه ها
void keyboardButtonActions(KeyboardButton &key, AppState &app);
void AllTabButtonActions(std::vector<AllTabButtons> &tab,AppState &app,ThemeGeneralTab &colorGeneral);
void RenderGeneralTap(std::vector<ButtonRect> buttons, AppState &app, ThemeGeneralTab &color);      // need to fix
void RenderTextureGeneral(std::vector<ButtonRect> buttons,AppState &app,ThemeGeneralTab &color,TabTexture& tabTexture,ButtonTextures &buttonTextures);
SDL_Texture* LoadTexture(SDL_Renderer* renderer,const std::string& file);
ButtonTextures LoadAllButtonTexture(SDL_Renderer* renderer);








int main( int argc, char* argv[])
{
    AppState app;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS);
    TTF_Init();

    SDL_DisplayMode full_Screen;
    SDL_GetCurrentDisplayMode(0,&full_Screen);
    app.FULL_SCREEN_W=full_Screen.w;
    app.FULL_SCREEN_H=full_Screen.h;
    SDL_GetDisplayUsableBounds(0,&app.AVAILABLE_SCREEN);
    app.W=app.LastW=app.AVAILABLE_SCREEN.w;
    app.H=app.LastH=app.AVAILABLE_SCREEN.h;
    app.X=app.AVAILABLE_SCREEN.x;
    app.Y=app.AVAILABLE_SCREEN.y;

    SDL_Window* window;
    Uint32 WND_flags =  SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE ;
    window=SDL_CreateWindow("Scratch",app.X,app.Y,app.W,app.H,WND_flags);
    SDL_SetWindowBordered(window,SDL_FALSE);
    SDL_RaiseWindow(window);
    app.window=window;
    //----------
    TabTexture tabTexture;
   // SDL_Surface* tempSurface = IMG_Load("")



    SDL_Renderer *renderer;
    renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);   //SDL_RENDERER_ACCELERATED or SDL_RENDERER_SOFTWARE
    app.renderer=renderer;
    ButtonTextures buttonTextures= LoadAllButtonTexture(app.renderer);
    // SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);


    // Variable declaration
    int iconSize=40;

    std:: vector<AllTabButtons> tabButtons= {
            {TAB_GENERAL,true ,  {     {CLOSE_BUTTON, SDL_Rect{app.W-app.W/30,0,app.W/30,app.H/25}},
                                       {WINDOW_BUTTON, SDL_Rect{app.W-app.W*2/30,0,app.W/30,app.H/25}},
                                       {MINIMIZED_BUTTON, SDL_Rect{app.W-app.W*3/30,0,app.W/30,app.H/25}},
                                       {SETTING_BUTTON, SDL_Rect{app.W*2/15,0,app.W/15,app.H/217*12},{3*iconSize,0,iconSize,iconSize}},
                                       {EDIT_BUTTON, SDL_Rect{app.W*1/15,0,app.W/15,app.H/217*12},{4*iconSize,0,iconSize,iconSize}},
                                       {FILE_BUTTON, SDL_Rect{0,0,app.W/15,app.H/217*12},{5*iconSize,0,iconSize,iconSize}},
            }
            }
    };


    KeyboardButton keyboardButton;
    MouseState mouse;
    SDL_GetMouseState(&mouse.x,&mouse.y);

    ThemeGeneralTab ColorGeneral={

    };

    SDL_Event e;
    SDL_PollEvent(&e);
    while(!app.endProgram)
    {
        resetKeyboardButtons(keyboardButton);
        resetButtonRect(tabButtons);
        resetMouseState(mouse);
        while(SDL_PollEvent(&e))
        {
            updateKeyboardButtons(keyboardButton,e);
            updateButtonRectAndMouseState(mouse,tabButtons,e);
        }
        keyboardButtonActions(keyboardButton,app);
        //------

        RenderTextureGeneral(tabButtons[0].buttons,app,ColorGeneral,tabTexture,buttonTextures);
        SDL_RenderCopy(app.renderer,tabTexture.general, nullptr, nullptr);
        AllTabButtonActions(tabButtons,app,ColorGeneral);
        SDL_RenderPresent(renderer);
        SDL_Delay(5);

    }










    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

bool isMouseInRect(MouseState &mouse,SDL_Rect &rect)
{
    return mouse.x>rect.x && mouse.x<rect.x+rect.w && mouse.y>rect.y && mouse.y<rect.y+rect.h;
}

void resetKeyboardButtons(KeyboardButton &key)
{
    memset(key.keyDown,false,sizeof(key.keyDown));  // can use sizeof(key.keyDown)=512
    memset(key.keyUp,false,sizeof(key.keyUp));     // sizeof(bool)=1
}
void resetButtonRect(std:: vector<AllTabButtons> &tab)
{
    for(auto &it1:tab)
        for(auto &it2:it1.buttons)
        {
            it2.leftClick=false;
            it2.rightClick=false;
        }

}
void resetMouseState(MouseState &mouse)
{
    mouse.rightUp=false;
    mouse.rightDown=false;
    mouse.leftUp=false;
    mouse.leftDown=false;
}

void updateKeyboardButtons(KeyboardButton &key,SDL_Event &e)
{
    if(e.type==SDL_KEYDOWN && e.key.repeat==0)
    {
        key.keyDown[e.key.keysym.scancode]=true;    //e.key.keysym.scancode or e.key.keysym.sym ?
        key.pressed[e.key.keysym.scancode]=true;
    }
    else if(e.type==SDL_KEYUP)
    {
        key.keyUp[e.key.keysym.scancode]=true;
        key.pressed[e.key.keysym.scancode]=false;
    }

}
void updateButtonRectAndMouseState(MouseState &mouse,std:: vector<AllTabButtons> &tab,SDL_Event &e)
{
    // چت جی بی تی میگفت اگر همرو if بزاری امن تر هست !
    // و میگه که مختصات موس رو در هر سه اپدیت کن که به مشکل نخوری
    if(e.type==SDL_MOUSEMOTION)
    {
        mouse.x=e.motion.x;
        mouse.y=e.motion.y;
        for(auto &it1:tab)
            if(it1.active)
                for(auto &it2:it1.buttons)
                {
                    if(isMouseInRect(mouse,it2.rect))
                        it2.onButton= true;
                    else
                        it2.onButton=false;
                }
    }
    else if(e.type==SDL_MOUSEBUTTONDOWN)
    {
        //  SDL_GetMouseState(&mouse.x,&mouse.y);
        // Update mouse state
        if(e.button.button==SDL_BUTTON_LEFT)
        {
            mouse.leftPressed= true;
            mouse.leftDown=true;
        }
        else if(e.button.button==SDL_BUTTON_RIGHT)
        {
            mouse.rightPressed=true;
            mouse.rightDown= true;
        }

        // Update Buttons
        for(auto &it1:tab)
            if(it1.active)
                for(auto &it2:it1.buttons)
                    if(isMouseInRect(mouse,it2.rect))
                    {
                        if(e.button.button==SDL_BUTTON_LEFT)
                            it2.leftPressed=true;
                        else if(e.button.button==SDL_BUTTON_RIGHT)
                            it2.rightPressed=true;
                    }
    }
    else if(e.type==SDL_MOUSEBUTTONUP)
    {
        //    SDL_GetMouseState(&mouse.x,&mouse.y);
        // Update mouse state
        if(e.button.button==SDL_BUTTON_LEFT)
        {
            mouse.leftPressed=false;
            mouse.leftUp=true;
        }
        else if(e.button.button==SDL_BUTTON_RIGHT)
        {
            mouse.rightPressed= false;
            mouse.rightUp= true;
        }

        // Update Buttons
        for(auto &it1:tab)
        {
            for(auto &it2:it1.buttons)
            {
                if(it1.active)
                {
                    if(isMouseInRect(mouse,it2.rect))
                    {
                        if(e.button.button==SDL_BUTTON_LEFT && it2.leftPressed)
                            it2.leftClick=true;
                        else if(e.button.button==SDL_BUTTON_RIGHT && it2.rightPressed)
                            it2.rightClick=true;
                    }
                }

                it2.leftPressed=false;
                it2.rightPressed=false;
            }
        }
    }

}

void keyboardButtonActions(KeyboardButton &key, AppState &app)
{
    if(key.keyDown[SDL_SCANCODE_ESCAPE])
    {
        app.endProgram=true;
    }
    if((key.pressed[SDL_SCANCODE_LALT] || key.pressed[SDL_SCANCODE_RALT]) && key.pressed[SDL_SCANCODE_F4])
    {
        app.endProgram=true;
    }
    if(key.keyDown[SDL_SCANCODE_F11])
    {
        if(app.fullScreen)
        {
            app.fullScreen=false;
            app.W=app.LastW;
            app.H=app.LastH;
            SDL_SetWindowFullscreen(app.window,0);
            // need to countinu ...
        }
        else
        {
            app.fullScreen=true;
            app.W=app.FULL_SCREEN_W;
            app.H=app.FULL_SCREEN_H;
            SDL_SetWindowFullscreen(app.window,SDL_WINDOW_FULLSCREEN_DESKTOP);
        }
    }   // have to finish ...
}
void AllTabButtonActions(std::vector<AllTabButtons> &tab,AppState &app,ThemeGeneralTab &colorGeneral)
{
    for(auto &it:tab)
        if(it.active)
            switch (it.ID) {
                case TAB_GENERAL:
                    RenderGeneralTap(it.buttons,app,colorGeneral);
                    break;

            }
}
void RenderGeneralTap(std::vector<ButtonRect> buttons, AppState &app, ThemeGeneralTab &color)
{
    SDL_SetRenderDrawColor(app.renderer,60,63,63,255);
    //SDL_RenderClear(app.renderer);
    int L=8;

    for(auto &it:buttons)
    {

        if(it.ID==CLOSE_BUTTON)
        {
            if(it.onButton)
            {
                SDL_SetRenderDrawColor(app.renderer,232,17,35,255);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }
            if(it.leftClick)
                app.endProgram=true;
            aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-L/ sqrt(2),it.rect.y+it.rect.h/2-L/sqrt(2),it.rect.x+it.rect.w/2+L/sqrt(2),it.rect.y+it.rect.h/2+L/sqrt(2),214,214,214,255);
            aalineRGBA(app.renderer,(it.rect.x+it.rect.w/2-L/ sqrt(2)),(it.rect.y+it.rect.h/2+L/sqrt(2)),(it.rect.x+it.rect.w/2+L/sqrt(2)),(it.rect.y+it.rect.h/2-L/sqrt(2)),214,214,214,255);
            aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-L/ sqrt(2),it.rect.y+it.rect.h/2-L/sqrt(2)-1,it.rect.x+it.rect.w/2+L/sqrt(2),it.rect.y+it.rect.h/2+L/sqrt(2)-1,214,214,214,255);
            aalineRGBA(app.renderer,(it.rect.x+it.rect.w/2-L/ sqrt(2)),(it.rect.y+it.rect.h/2+L/sqrt(2))-1,(it.rect.x+it.rect.w/2+L/sqrt(2)),(it.rect.y+it.rect.h/2-L/sqrt(2))-1,214,214,214,255);
        }
        else if(it.ID==WINDOW_BUTTON)
        {
            if(it.onButton)
            {
                SDL_SetRenderDrawColor(app.renderer,79,82,84,255);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }
            SDL_SetRenderDrawColor(app.renderer,214,214,214,255);
            SDL_Rect rectwindow={it.rect.x+it.rect.w/2-it.rect.w/10,it.rect.y+it.rect.h/2-it.rect.h/7,it.rect.w*2/10,it.rect.h*2/7};
            SDL_RenderDrawRect(app.renderer,&rectwindow);

        }
        else if(it.ID==MINIMIZED_BUTTON)
        {
            if(it.onButton)
            {
                SDL_SetRenderDrawColor(app.renderer,79,82,84,255);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }
            int s=6;
            aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-s,it.rect.y+it.rect.h/2,it.rect.x+it.rect.w/2+s,it.rect.y+it.rect.h/2,214,214,214,255);
            if(it.leftClick )
            {
                SDL_MinimizeWindow(app.window);
                it.onButton=false;
            }

        }
        else if(it.ID==SETTING_BUTTON)
        {
            if(it.onButton)
            {
                SDL_SetRenderDrawColor(app.renderer,79,82,84,255);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }


            if(it.leftClick )
            {
                it.onButton=false;
            }

        }
        else if(it.ID==FILE_BUTTON)
        {
            if(it.onButton)
            {
                SDL_SetRenderDrawColor(app.renderer,79,82,84,255);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }


            if(it.leftClick )
            {
                it.onButton=false;
            }

        }
        else if(it.ID==EDIT_BUTTON)
        {
            if(it.onButton)
            {
                SDL_SetRenderDrawColor(app.renderer,79,82,84,255);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }


            if(it.leftClick )
            {
                it.onButton=false;
            }

        }


    }
}
void RenderTextureGeneral(std::vector<ButtonRect> buttons,AppState &app,ThemeGeneralTab &color,TabTexture& tabTexture,ButtonTextures &buttonTextures){
    //------
    tabTexture.general= SDL_CreateTexture(app.renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,app.W,app.H);
    SDL_SetTextureBlendMode(tabTexture.general,SDL_BLENDMODE_BLEND);


    //----------
    SDL_SetRenderTarget(app.renderer,tabTexture.general);
    SDL_SetRenderDrawColor(app.renderer,255,255,255,255);
    SDL_RenderClear(app.renderer);

    // نوار بالا
    int barHeight =0;
    for(auto & it : buttons)
    {
        if(it.ID == FILE_BUTTON)
        { barHeight = it.rect.h;
            break;

        }
    }
    SDL_Rect topBar ={0,0,app.W,barHeight};
    SDL_SetRenderDrawColor(app.renderer,138,85,215,225);
    SDL_RenderFillRect(app.renderer,&topBar);


    // ایکون ها

    for(auto& it :buttons)
    {
        if(it.ID==SETTING_BUTTON){
            SDL_RenderCopy(app.renderer, buttonTextures.setting, nullptr,&it.rect);



        }


    }
    SDL_SetRenderTarget(app.renderer,nullptr);










}


SDL_Texture* LoadTexture(SDL_Renderer* renderer,const std::string& file){
    SDL_Surface* surface = IMG_Load(file.c_str());
    if(!surface)
    {
        std::cerr<<"Failed to load image: "<< file<<"Error:"<<IMG_GetError()<<std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,surface) ;
    SDL_FreeSurface(surface);
    return texture;

}
ButtonTextures LoadAllButtonTexture(SDL_Renderer* renderer){
    ButtonTextures textures;
    textures.setting = LoadTexture(renderer,"set.png");
    textures.file = LoadTexture(renderer,"file.png");
    textures.flesh = LoadTexture(renderer,"flesh.png");
    return textures;
}
