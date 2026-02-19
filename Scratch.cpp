#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <c++/iostream>

#include <map>
#include <string>

//   Button names
constexpr int CLOSE_BUTTON=9;
constexpr int WINDOW_BUTTON=10;
constexpr int MINIMIZED_BUTTON=11;
constexpr int FILE_BUTTON=14;
constexpr int EDIT_BUTTON=15;
constexpr int SETTING_BUTTON=16;
constexpr int CODE_BUTTON=17;
constexpr int COSTUMES_BUTTON=18;
constexpr int SOUNDS_BUTTON=19;
constexpr int GO_BUTTON=20;
constexpr int STOP_BUTTON=21;
constexpr int FULLSCREEN_BUTTON=22;


// tab names
constexpr int TAB_GENERAL=12;
constexpr int TAB_CODE=13;
constexpr int TAB_COSTUMES=14;
constexpr int TAB_SOUNDS=15;

constexpr int Motion=0;
constexpr int Looks=1;
constexpr int Sound=2;
constexpr int Events=3;
constexpr int Control=4;
constexpr int Sensing=5;
constexpr int Operators=6;
constexpr int Variables=7;
constexpr int MyBlocks=8;

constexpr int WorkSpace=17;

constexpr int moveBlock=18;
//------------------ sprite names
constexpr int gorbaFront=100;
constexpr int gorbaBack=101;

// structs

enum struct BlockType {Normal,Loop,Start};

struct Block{
    int index;
    int ID;
    BlockType type;
    int next;

    SDL_Rect rect;
    int startloopindex;    // only for loops
    int endloopindex;

    int parametr=0;
    std::string text;
};
struct AppState{
    bool endProgram=false;
    bool fullScreen=false;
    bool maximize=false;
    int W,H,X=0,Y=0;
    int LastW,LastH;

    int FULL_SCREEN_W,FULL_SCREEN_H;
    SDL_Rect AVAILABLE_SCREEN;

    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Texture* textureHelperText= nullptr;
    SDL_Texture* textureHelperImage= nullptr;
    // Code Tab
    // در صورت بروز مشکل برای عوض کردن تب ها این بخش چک بشه
    bool activeCodePage[9]= {};
    std::map<std::string,TTF_Font*> font;
    std::vector<Block> block;
};

struct MouseState{
    int x=0,y=0;

    int xLeftDown=0,yLeftDown=0;
    int xRightDown=0,yRightDown=0;
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

    SDL_Color topBar ={133,92,214,225};
    SDL_Color topBarhaber={113,78,182,255};
    SDL_Color white={255,255,255,255};
    SDL_Color closeButton={214,214,214,255};
    SDL_Color closeButtonMouse={232,17,35,255};
    SDL_Color windowButton={214,214,214,255};
    SDL_Color windowButtonMouse={79,82,84,255};
    SDL_Color minimizeButton={214,214,214,255};
    SDL_Color minimizeButtonMouse={79,82,84,255/**/};
};
struct ThemeCodeTab{

    SDL_Color line={185,193,206,255};
    SDL_Color CodeBackground={249,249,249,255};
    SDL_Color motionBackground={249,249,249,255};
    SDL_Color leftPaned={255,255,255,255};
    SDL_Color leftButtonClicked={233,238,242,255};
    SDL_Color leftPanelText={87, 94, 117,255};
    SDL_Color leftPanelTextMouse={76, 151, 255,255};

    SDL_Color circle[9]={
            {76,151,255,255},
            {153,102,255,255},
            {207,99,207,255},
            {255,191,0,255},
            {255,171,25,255},
            {92,177,214,255},
            {89,192,89,255},
            {255,140,26,255},
            {255,102,128,255}
    };

    SDL_Color circleBorder[9]={
            {51,115,204,255},
            {119,77,203,255},
            {189,66,189,255},
            {204,153,0,255},
            {207,139,23,255},
            {46,142,184,255},
            {56,148,56,255},
            {219,110,0,255},
            {255,51,85,255}
    };



};
struct Theme{
    ThemeGeneralTab general;
    ThemeCodeTab code;
};
struct TabTexture {
    SDL_Texture* general= nullptr;
    SDL_Texture* code= nullptr;
};


struct ButtonTextures{
    SDL_Texture* setting = nullptr;
    SDL_Texture* file = nullptr;
    SDL_Texture* flesh = nullptr;
    SDL_Texture* edit = nullptr;
    SDL_Texture * code= nullptr;
    SDL_Texture * custumes= nullptr;
    SDL_Texture * sounds= nullptr;
    SDL_Texture * codeA= nullptr;
    SDL_Texture * custumesA= nullptr;
    SDL_Texture * soundsA= nullptr;
    SDL_Texture * Go= nullptr;
    SDL_Texture * Stop= nullptr;
    SDL_Texture * Fullscreen= nullptr;

};
struct Sprite {
    int ID;
    float scratchX=0;
    float scratchY=0;
    float w;
    float h;
    SDL_Texture *texture = nullptr;
    double angle=0.0;
    double scale=1.0;
    bool show =true;


    double dx=0.0;
    double dy=0.0;


    int layer=0;
   // std::string costume;
    //std::map<std::,std::
};
struct Stage{
    SDL_Rect rect;
    std::vector<Sprite> sprites;
    int activeBackground=0;
    std::vector<SDL_Texture *> backgrounds;
};


//// Mamad function

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
void updateButtonRectAndMouseState(MouseState &mouse,std:: vector<AllTabButtons> &tab,SDL_Event &e);

// Action function
// عملیات مربوط را در هر فریم انجام میدهد با توجه به توابع مربوط به دکمه ها
void keyboardButtonActions(KeyboardButton &key, AppState &app,std:: vector<AllTabButtons> &tab);
void AllTabButtonActions(std::vector<AllTabButtons> &tab,AppState &app,Theme &color,TabTexture &texture,MouseState &mouse);
void RenderGeneralTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeGeneralTab &color);      // need to fix
void RenderTextureCodeTab(std::vector<ButtonRect> &buttons,AppState &app,ThemeCodeTab &color,TabTexture &texture);
void RenderCodeTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeCodeTab &,TabTexture &tex,MouseState &mouse);
void active(int id,std:: vector<AllTabButtons> &tab,bool ac=true);
void text( AppState &app,int x,int y,std::string T,std::string F,SDL_Color color,bool xyNotMiddle=false);
void image(AppState &app,int x,int y,double scale,std::string I,bool xtMiddle=false,int readX=0,int readY=0,double readWScale=1,double readHScale=1);

//// Golab function
void RenderTextureGeneral(std::vector<ButtonRect> buttons,AppState &app,ThemeGeneralTab &color,TabTexture& tabTexture,ButtonTextures &buttonTextures);
SDL_Texture* LoadTexture(SDL_Renderer* renderer,const std::string& file);
ButtonTextures LoadAllButtonTexture(SDL_Renderer* renderer);
void DestroyButtonTexture(ButtonTextures &textures);
void UpdateSprite (Sprite& s);
void RenderStage(AppState & app, Stage &stage,Sprite s);



int main( int argc, char* argv[]) {
    AppState app;
    app.activeCodePage[0] = true;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS);
    TTF_Init();

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
    }

    SDL_DisplayMode full_Screen;
    SDL_GetCurrentDisplayMode(0, &full_Screen);
    app.FULL_SCREEN_W = full_Screen.w;
    app.FULL_SCREEN_H = full_Screen.h;
    SDL_GetDisplayUsableBounds(0, &app.AVAILABLE_SCREEN);
    app.W = app.LastW = app.AVAILABLE_SCREEN.w;
    app.H = app.LastH = app.AVAILABLE_SCREEN.h;
    app.X = app.AVAILABLE_SCREEN.x;
    app.Y = app.AVAILABLE_SCREEN.y;

    SDL_Window *window;
    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
    window = SDL_CreateWindow("Scratch", app.X, app.Y, app.W, app.H, WND_flags);
    SDL_SetWindowBordered(window, SDL_FALSE);
    SDL_RaiseWindow(window);
    app.window = window;

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    //----------
    TabTexture tabTexture;
    // SDL_Surface* tempSurface = IMG_Load("")



    SDL_Renderer *renderer;

    renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);   //SDL_RENDERER_ACCELERATED or SDL_RENDERER_SOFTWARE
    // Mamad
    //  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
    app.renderer=renderer;
    ButtonTextures buttonTextures= LoadAllButtonTexture(app.renderer);




    // Variable declaration
    int iconSize=40;

    std::vector<AllTabButtons> tabButtons = {
            {TAB_GENERAL,true ,  {     {CLOSE_BUTTON, SDL_Rect{app.W-app.W/30,0,app.W/30,app.H/25}},
                                         {WINDOW_BUTTON, SDL_Rect{app.W-app.W*2/30,0,app.W/30,app.H/25}},
                                         {MINIMIZED_BUTTON, SDL_Rect{app.W-app.W*3/30,0,app.W/30,app.H/25}},
                                         {FILE_BUTTON, SDL_Rect{0,0,app.W*91/1503,app.H*56/867}},
                                         {EDIT_BUTTON, SDL_Rect{app.W*91/1503,0,app.W*105/1503,app.H*56/867}},
                                         {SETTING_BUTTON, SDL_Rect{app.W*196/1503,0,app.W*120/1503,app.H*56/867}},
                                         {CODE_BUTTON, SDL_Rect{0,app.H*67/609,app.W*95/1503,app.H*25/609}},
                                         {COSTUMES_BUTTON, SDL_Rect{app.W*95/1503,app.H*67/609,app.W*120/1503,app.H*25/609}},
                                         {SOUNDS_BUTTON, SDL_Rect{app.W*215/1503,app.H*67/609,app.W*105/1503,app.H*25/609}},
                                         {GO_BUTTON, SDL_Rect{app.W*950/1503,app.H*64/609,app.W*33/1503,app.H*31/867}},
                                         {STOP_BUTTON, SDL_Rect{app.W*983/1503,app.H*64/609,app.W*33/1503,app.H*31/867}},
                                         {FULLSCREEN_BUTTON, SDL_Rect{app.W*1462/1503,app.H*64/609,app.W*33/1503,app.H*31/867}}}

            },
            {TAB_CODE,    true, {{Motion,       SDL_Rect{0, app.H * 90 / 609, app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Looks,         SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 1 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Sound,            SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 2 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Events, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 3 / 609, app.W * 60 / 1365,app.H * 45 / 609}},
                                         {Control, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 4 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Sensing, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 5 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Operators, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 6 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Variables, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 7 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {MyBlocks, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 8 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {WorkSpace, SDL_Rect{app.W*250/1365,app.H*90/559,app.W*853/1365-15*app.W/1365-app.W*250/1365,app.H-app.H*90/559}}
                                 }
            }};
    Stage stage;
    Sprite gorba{gorbaFront,0, 0,100,100, LoadTexture(app.renderer,"icons/gorba(1).png"),0,0,0};




    Theme light, color;
    color = light; // default color

    float scale=std::min(app.W/1365.0,app.H/610.0);

    app.font["Roman10.4"] = TTF_OpenFont("fonts/HelveticaNeue-Roman.otf", std::round(10.4*scale));
    if (!app.font["Roman10.4"])
    {
        std::cout << "OpenFont Roman10.4 failed: " << TTF_GetError() << "\n";
        return -1;
    }
    app.font["Roman11"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(11*scale));
    app.font["Roman12"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(12*scale));
    app.font["Roman13"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(13*scale));
    app.font["Roman14"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(14*scale));
    app.font["Bold12"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(12*scale));
    app.font["Bold13"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(13*scale));
    app.font["Bold14"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(14*scale));
    app.font["Bold19"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(19*scale));
    app.font["Medium12"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(12*scale));
    app.font["Medium14"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(14*scale));
    app.font["Thin14"]=TTF_OpenFont("fonts/HelveticaNeue-Thin.otf",std::round(14*scale));



    //

    TabTexture texture;
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    //==========================





    for(auto &it1:tabButtons)
    {
        if(it1.ID==TAB_GENERAL)
        {

        }
        if(it1.ID==TAB_CODE)
        {
            RenderTextureCodeTab(it1.buttons,app,color.code,texture);
        }
    }




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
        keyboardButtonActions(keyboardButton,app,tabButtons);
        RenderTextureGeneral(tabButtons[0].buttons,app,ColorGeneral,tabTexture,buttonTextures);
        SDL_RenderCopy(app.renderer,tabTexture.general, nullptr, nullptr);
        AllTabButtonActions(tabButtons,app,color,texture,mouse);
        RenderStage(app,stage,gorba);

        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }



    SDL_DestroyTexture(tabTexture.general);
    DestroyButtonTexture(buttonTextures);





    SDL_DestroyTexture(app.textureHelperImage);
    SDL_DestroyTexture(app.textureHelperText);
    for(auto &it:app.font)
    {
        TTF_CloseFont(it.second);
    }
    SDL_DestroyTexture(texture.code);
    SDL_DestroyTexture(texture.general);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

//// Mamad function

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
            SDL_GetMouseState(&mouse.xLeftDown,&mouse.yLeftDown);
        }
        else if(e.button.button==SDL_BUTTON_RIGHT)
        {
            mouse.rightPressed=true;
            mouse.rightDown= true;
            SDL_GetMouseState(&mouse.xRightDown,&mouse.yRightDown);
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
void keyboardButtonActions(KeyboardButton &key, AppState &app,std:: vector<AllTabButtons> &tab)
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
            active(CLOSE_BUTTON,tab);
            active(WINDOW_BUTTON,tab);
            active(MINIMIZED_BUTTON,tab);

            // need to countinu ...
        }
        else
        {
            app.fullScreen=true;
            app.W=app.FULL_SCREEN_W;
            app.H=app.FULL_SCREEN_H;
            SDL_SetWindowFullscreen(app.window,SDL_WINDOW_FULLSCREEN_DESKTOP);
            active(CLOSE_BUTTON,tab,false);
            active(WINDOW_BUTTON,tab,false);
            active(MINIMIZED_BUTTON,tab,false);
        }
    }   // have to finish ...
}
void AllTabButtonActions(std::vector<AllTabButtons> &tab,AppState &app,Theme &color,TabTexture &texture,MouseState &mouse)
{
    for(auto &it:tab)
        if(it.active)
            switch (it.ID) {
                case TAB_GENERAL:
                    RenderGeneralTap(it.buttons,app,color.general);
                    break;
                case TAB_CODE:
                    RenderCodeTap(it.buttons,app,color.code,texture,mouse);
                    break;

            }
}
void RenderGeneralTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeGeneralTab &color)
{
    float L=6;

    for(auto &it:buttons)
    {
        if(it.ID==CLOSE_BUTTON)
        {
            if(it.active)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,color.closeButtonMouse.r,color.closeButtonMouse.g,color.closeButtonMouse.b,color.closeButtonMouse.a);
                    SDL_RenderFillRect(app.renderer,&it.rect);
                }
                if(it.leftClick)
                    app.endProgram=true;
                aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-L/ sqrt(2),it.rect.y+it.rect.h/2-L/sqrt(2),it.rect.x+it.rect.w/2+L/sqrt(2),it.rect.y+it.rect.h/2+L/sqrt(2),color.closeButton.r,color.closeButton.g,color.closeButton.b,color.closeButton.a);
                aalineRGBA(app.renderer,(it.rect.x+it.rect.w/2-L/ sqrt(2)),(it.rect.y+it.rect.h/2+L/sqrt(2)),(it.rect.x+it.rect.w/2+L/sqrt(2)),(it.rect.y+it.rect.h/2-L/sqrt(2)),color.closeButton.r,color.closeButton.g,color.closeButton.b,color.closeButton.a);
                aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-L/ sqrt(2),it.rect.y+it.rect.h/2-L/sqrt(2)-1,it.rect.x+it.rect.w/2+L/sqrt(2),it.rect.y+it.rect.h/2+L/sqrt(2)-1,color.closeButton.r,color.closeButton.g,color.closeButton.b,color.closeButton.a);
                aalineRGBA(app.renderer,(it.rect.x+it.rect.w/2-L/ sqrt(2)),(it.rect.y+it.rect.h/2+L/sqrt(2))-1,(it.rect.x+it.rect.w/2+L/sqrt(2)),(it.rect.y+it.rect.h/2-L/sqrt(2))-1,color.closeButton.r,color.closeButton.g,color.closeButton.b,color.closeButton.a);
            }
        }
        else if(it.ID==WINDOW_BUTTON)
        {
            if(it.active)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,color.windowButtonMouse.r,color.windowButtonMouse.g,color.windowButtonMouse.b,color.windowButtonMouse.a);
                    SDL_RenderFillRect(app.renderer,&it.rect);
                }
                SDL_SetRenderDrawColor(app.renderer,color.windowButton.r,color.windowButton.g,color.windowButton.b,color.windowButton.a);
                SDL_Rect rectWindow={it.rect.x+it.rect.w/2-it.rect.w/10,it.rect.y+it.rect.h/2-it.rect.w/10,it.rect.w*2/10,it.rect.w*2/10};
                SDL_RenderDrawRect(app.renderer,&rectWindow);
            }
//           if(it.leftClick)
//            {
//                if(app.maximize)
//                {
//                    SDL_SetWindowSize(app.window,app.AVAILABLE_SCREEN.w,app.AVAILABLE_SCREEN.h);
//                    app.maximize=false;
//                }
//                else
//                {
//                    SDL_SetWindowSize(app.window,app.W/2,app.H/2);
//                    SDL_SetWindowPosition(app.window,app.W/4,app.H/4);
//                    app.W=app.W/2;
//                    app.H=app.H/2;
//                    app.X=app.W/4;
//                    app.Y=app.H/4;
//                    app.maximize=true;
//                }
//            }

        }
        else if(it.ID==MINIMIZED_BUTTON)
        {
            if(it.active)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,color.minimizeButtonMouse.r,color.minimizeButtonMouse.r,color.minimizeButtonMouse.b,color.minimizeButtonMouse.a);
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
        }
        else if(it.ID==SETTING_BUTTON)
        {
            if(it.onButton)
            {
//                SDL_SetRenderDrawBlendMode(app.renderer,SDL_BLENDMODE_BLEND);
//                SDL_SetRenderDrawColor(app.renderer,color.topBarhaber.r,color.topBarhaber.g,color.topBarhaber.b,60);
//                SDL_RenderFillRect(app.renderer,&it.rect);
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
//                SDL_SetRenderDrawColor(app.renderer,79,82,84,50);
//                SDL_RenderFillRect(app.renderer,&it.rect);
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
//
//
            }


            if(it.leftClick )
            {
                it.onButton=false;
            }

        }

    }
}
void RenderCodeTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeCodeTab &color,TabTexture &texture,MouseState &mouse)
{
    // با تغییر ابعاد دکمه در وکتور در همه  جا عوض نمیشه
    for(auto &it:buttons)
    {
        if(0<=it.ID && it.ID<=8 && it.leftClick)
        {
            memset(app.activeCodePage,0,sizeof(app.activeCodePage));
            app.activeCodePage[it.ID]=true;
            RenderTextureCodeTab(buttons,app,color,texture);
            break;
        }
    }
    SDL_RenderCopy(app.renderer,texture.code,NULL,NULL);
    for(auto it:buttons)
    {
        if(it.ID<=8 ,0<=it.ID)
        {
            if(it.ID==Motion)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Motion","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Motion","Roman10.4",color.leftPanelText);
            }
            else if(it.ID==Looks)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Looks","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Looks","Roman10.4",color.leftPanelText);
            }
            else if(it.ID==Sound)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Sound","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Sound","Roman10.4",color.leftPanelText);
            }
            else if(it.ID==Events)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Events","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Events","Roman10.4",color.leftPanelText);
            }
            else if(it.ID==Control)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Control","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Control","Roman10.4",color.leftPanelText);
            }
            else if(it.ID==Sensing)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Sensing","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Sensing","Roman10.4",color.leftPanelText);
            }
            else if(it.ID==Operators)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Operators","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Operators","Roman10.4",color.leftPanelText);
            }
            else if(it.ID==Variables)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Variables","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Variables","Roman10.4",color.leftPanelText);
            }
            else if(it.ID==MyBlocks)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"My Blocks","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"My Blocks","Roman10.4",color.leftPanelText);
            }
        }


    }


}
void RenderTextureCodeTab(std::vector<ButtonRect> &buttons,AppState &app,ThemeCodeTab &color,TabTexture &tex)
{
    if(tex.code)
        SDL_DestroyTexture(tex.code);

    tex.code=SDL_CreateTexture(app.renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,app.W, app.H);
    SDL_SetTextureBlendMode(tex.code,SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(app.renderer,tex.code);

    int x,y,w;
    for(auto &it1:buttons)
        if(it1.ID==Motion)
        {
            w=it1.rect.w;
            x=it1.rect.x;
            y=it1.rect.y;
            break;
        }

    SDL_SetRenderDrawColor(app.renderer,0,0,0,0);
    SDL_RenderClear(app.renderer);

    roundedBoxRGBA(app.renderer,0,y,app.W*853/1365,app.H,15*app.W/1365,color.CodeBackground.r,color.CodeBackground.g,color.CodeBackground.b,color.CodeBackground.a);

    SDL_Rect leftPanel={0,y,w,app.H-w};
    SDL_SetRenderDrawColor(app.renderer,color.leftPaned.r,color.leftPaned.g,color.leftPaned.b,color.leftPaned.a);
    SDL_RenderFillRect(app.renderer,&leftPanel);

    SDL_Rect  motion={w,y,app.W*250/1365,app.H-app.H*90/559};
    SDL_SetRenderDrawColor(app.renderer,color.motionBackground.r,color.motionBackground.g,color.motionBackground.b,color.motionBackground.a);
    SDL_RenderFillRect(app.renderer,&motion);

    for(auto &it:buttons)
        if(0<=it.ID && it.ID<=8)
        {
            if(app.activeCodePage[it.ID])
            {
                SDL_SetRenderDrawColor(app.renderer,color.leftButtonClicked.r,color.leftButtonClicked.g,color.leftButtonClicked.b,color.leftButtonClicked.a);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }
            filledCircleRGBA(app.renderer,it.rect.w/2,it.rect.y+app.H*17/609,app.H*8.5/609-1,color.circle[it.ID].r,color.circle[it.ID].g,color.circle[it.ID].b,color.circle[it.ID].a);
            aacircleRGBA(app.renderer,it.rect.w/2,it.rect.y+app.H*17/609,app.H*8.5/609,color.circle[it.ID].r,color.circle[it.ID].g,color.circle[it.ID].b,color.circle[it.ID].a);
            aacircleRGBA(app.renderer,it.rect.w/2,it.rect.y+app.H*17/609,app.H*8.5/609-1,color.circle[it.ID].r,color.circle[it.ID].g,color.circle[it.ID].b,color.circle[it.ID].a);
            aacircleRGBA(app.renderer,it.rect.w/2,it.rect.y+app.H*17/609,app.H*8.5/609,color.circleBorder[it.ID].r,color.circleBorder[it.ID].g,color.circleBorder[it.ID].b,color.circleBorder[it.ID].a);

        }


    roundedRectangleRGBA(app.renderer,-20,y,app.W*853/1365,app.H,15,color.line.r,color.line.g,color.line.b,color.line.a);
    aalineRGBA(app.renderer,w,y,w,app.H,color.line.r,color.line.g,color.line.b,color.line.a);
    aalineRGBA(app.renderer,w+app.W*250/1365,y,w+app.W*250/1365,app.H,color.line.r,color.line.g,color.line.b,color.line.a);



    SDL_SetRenderTarget(app.renderer,NULL);
}
void text( AppState &app,int x,int y,std::string T,std::string F,SDL_Color color,bool xyNotMiddle)
{
    if(!T.empty())
    {
        TTF_Font* Font=app.font[F];
        SDL_Surface* surface= TTF_RenderUTF8_Blended(Font,T.c_str(),color);
        if(!surface){
            std::cout << "TTF_RenderUTF8_Blended failed: " << TTF_GetError() << "\n";
            app.endProgram=true;
            return;
        }
        app.textureHelperText= SDL_CreateTextureFromSurface(app.renderer, surface);
        if(!app.textureHelperText){
            std::cout << "SDL_CreateTextureFromSurface failed: " << SDL_GetError() << "\n";
            app.endProgram=true;
            SDL_FreeSurface(surface);
            return;
        }
        SDL_FreeSurface(surface);
        int w,h;
        SDL_QueryTexture(app.textureHelperText, NULL, NULL, &w, &h);
        SDL_Rect rr;
        if(xyNotMiddle)
            rr={x,y,w,h};
        else
            rr={x-w/2,y-h/2,w,h};
        SDL_RenderCopy(app.renderer, app.textureHelperText, NULL, &rr);
        SDL_DestroyTexture(app.textureHelperText);
        app.textureHelperText = nullptr;
    }

}

void active(int id,std:: vector<AllTabButtons> &tab,bool ac)
{
    for(auto &it1:tab)
    {
        if(it1.ID==id)
        {
            it1.active=ac;
            return;
        }
        for(auto &it2:it1.buttons)
            if(it2.ID==id)
            {
                it2.active=ac;
                return;
            }
    }

}
void image(AppState &app,int x,int y,double scale,std::string I,bool xyMiddle,int readX,int readY,double readWScale,double readHScale)
{
    app.textureHelperImage= IMG_LoadTexture(app.renderer,I.c_str());
    if(!app.textureHelperImage)
    {
        std::cout << "TTF_RenderUTF8_Blended failed: " << TTF_GetError() << "\n";
        SDL_DestroyTexture(app.textureHelperImage);
        app.endProgram=true;
        return;
    }
    int imageW,imageH;
    SDL_QueryTexture(app.textureHelperImage,NULL,NULL,&imageW,&imageH);
    SDL_Rect rect;
    if(xyMiddle)
    {
        rect.x=x-(double)imageW/scale/2.0;
        rect.y=y-(double)imageH/scale/2.0;
        rect.w=(double)imageW/scale;
        rect.h=(double)imageH/scale;
    }
    else
    {
        rect.x=x;
        rect.y=y;
        rect.w=(double)imageW/scale;
        rect.h=(double)imageH/scale;
    }

    SDL_Rect scr;
    if(readX>imageW || readY>imageH)
    {
        std::cout<<"Eror , out of renge of image"<<std::endl;
        return;
    }
    scr.x=readX;
    scr.y=readY;
    scr.w=readX+(double)imageW*readWScale>imageW ? imageW-readX:(double)imageW*readWScale;
    scr.h=readY+(double)imageH*readHScale>imageH ? imageH-readY:(double)imageH*readHScale;
    SDL_RenderCopy(app.renderer,app.textureHelperImage,&scr,&rect);
    SDL_DestroyTexture(app.textureHelperImage);
    app.textureHelperText = nullptr;
}

//// Golab function

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
    textures.setting = LoadTexture(renderer,"icons/set.png");
    textures.file = LoadTexture(renderer,"icons/file.png");
    textures.flesh = LoadTexture(renderer,"icons/flesh.png");
    textures.edit = LoadTexture(renderer,"icons/edit.png");
    textures.code= LoadTexture(renderer,"icons/code.png");
    textures.custumes= LoadTexture(renderer,"icons/brush.png");
    textures.sounds= LoadTexture(renderer,"icons/sound.png");
    textures.codeA= LoadTexture(renderer,"icons/codeA.png");
    textures.custumesA= LoadTexture(renderer,"icons/brushA.png");
    textures.soundsA= LoadTexture(renderer,"icons/soundA.png");
    textures.Go= LoadTexture(renderer,"icons/Go.png");
    textures.Stop= LoadTexture(renderer,"icons/Stop.png");
    textures.Fullscreen= LoadTexture(renderer,"icons/Fullscreen.png");


    return textures;
}
void DestroyButtonTexture(ButtonTextures &textures)
{
    if(textures.setting) { SDL_DestroyTexture(textures.setting); textures.setting = nullptr; }
    if(textures.file)    { SDL_DestroyTexture(textures.file); textures.file = nullptr; }
    if(textures.flesh)   { SDL_DestroyTexture(textures.flesh); textures.flesh = nullptr; }
    if(textures.edit)    { SDL_DestroyTexture(textures.edit); textures.edit = nullptr; }
}
void RenderTextureGeneral(std::vector<ButtonRect> buttons,AppState &app,ThemeGeneralTab &color,TabTexture& tabTexture,ButtonTextures &buttonTextures){
    //------
    if(tabTexture.general){
        SDL_DestroyTexture(tabTexture.general);
        tabTexture.general= nullptr;
    }
    tabTexture.general= SDL_CreateTexture(app.renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,app.W,app.H);
    SDL_SetTextureBlendMode(tabTexture.general,SDL_BLENDMODE_BLEND);


    //----------
    SDL_SetRenderTarget(app.renderer,tabTexture.general);
    SDL_SetRenderDrawColor(app.renderer,230,240,255,255);
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
    SDL_SetRenderDrawColor(app.renderer,color.topBar.r,color.topBar.g,color.topBar.b,color.topBar.a);
    SDL_RenderFillRect(app.renderer,&topBar);
    //صفحه استیج
    SDL_SetRenderDrawColor(app.renderer,255,255,255,255);
    roundedBoxRGBA(app.renderer,app.W*950/1503,app.H*90/609,app.W*1496/1503,app.H*366/609,15*app.W/1365,255,255,255,255);
    roundedRectangleRGBA(app.renderer,app.W*950/1503,app.H*90/609,app.W*1496/1503,app.H*366/609,15*app.W/1365,185,193,206,255);


    // ایکون ها

    for(auto& it :buttons) {
        if (it.ID == SETTING_BUTTON) {
            if (it.onButton) {
                SDL_SetRenderDrawColor(app.renderer, color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,
                                       255);
                SDL_RenderFillRect(app.renderer, &it.rect);

            }
            std::string u = "Settings";
            SDL_Rect set = {app.W * 208 / 1503, app.H * 19 / 867, 20, 20};
            SDL_Rect flesh = {app.W * 291 / 1503, app.H * 25 / 867, 8, 5};
            SDL_RenderCopy(app.renderer, buttonTextures.setting, nullptr, &set);
            SDL_RenderCopy(app.renderer, buttonTextures.flesh, nullptr, &flesh);
            text(app, app.W * 259 / 1503, app.H * 28 / 867, u, "Bold12", color.white);

        }
        else if (it.ID == EDIT_BUTTON) {
            if (it.onButton) {
                SDL_SetRenderDrawColor(app.renderer, color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,
                                       255);
                SDL_RenderFillRect(app.renderer, &it.rect);

            }
            std::string u = "Edit";
            SDL_Rect edit = {app.W * 108 / 1503, app.H * 19 / 867, 21, 20};
            SDL_Rect flesh = {app.W * 163 / 1503, app.H * 25 / 867, 8, 5};
            SDL_RenderCopy(app.renderer, buttonTextures.edit, nullptr, &edit);
            SDL_RenderCopy(app.renderer, buttonTextures.flesh, nullptr, &flesh);
            text(app, app.W * 145 / 1503, app.H * 28 / 867, u, "Bold12", color.white);


        }
        else if (it.ID == FILE_BUTTON) {
            if (it.onButton) {
                SDL_SetRenderDrawColor(app.renderer, color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,
                                       255);
                SDL_RenderFillRect(app.renderer, &it.rect);

            }
            std::string u = "File";
            SDL_Rect file = {app.W * 15 / 1503, app.H * 19 / 867, 21, 20};
            SDL_Rect flesh = {app.W * 72 / 1503, app.H * 25 / 867, 8, 5};
            SDL_RenderCopy(app.renderer, buttonTextures.file, nullptr, &file);
            SDL_RenderCopy(app.renderer, buttonTextures.flesh, nullptr, &flesh);
            text(app, app.W * 50 / 1503, app.H * 28 / 867, u, "Bold12", color.white);


        }
        else if (it.ID == CODE_BUTTON) {
            roundedRectangleRGBA(app.renderer, 0, it.rect.y, it.rect.w, it.rect.y + 60, 10, 185, 193, 209, 255);
            roundedBoxRGBA(app.renderer, 1, it.rect.y + 1, it.rect.w - 1, it.rect.y + 60, 10, 217, 227, 242, 255);
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, 1, it.rect.y + 1, it.rect.w - 1, it.rect.y + 60, 10, 230, 240, 255, 255);

            }
            std::string u = "Code";
            SDL_Rect code = {it.rect.w / 4 - 8, it.rect.y + it.rect.h / 2 - it.rect.h / 4 * (1), 22, 22};
            SDL_RenderCopy(app.renderer, buttonTextures.code, nullptr, &code);
            text(app, code.x + 22, code.y + 5, u, "Medium12", {123, 131, 152, 255}, true);


        }
        else if (it.ID == COSTUMES_BUTTON) {
            roundedRectangleRGBA(app.renderer, 95 * app.W / 1503, it.rect.y, it.rect.w+it.rect.x, it.rect.y + 60, 10, 185, 193,
                                 209, 255);
            roundedBoxRGBA(app.renderer, 1 + 95 * app.W / 1503, it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10, 217,
                           227, 242, 255);
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, 1 + 95 * app.W / 1503, it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10,
                               230, 240, 255, 255);

            }
            std::string u = "Costumes";
            SDL_Rect costom = {it.rect.x + it.rect.w / 15, it.rect.y + it.rect.h / 2 - it.rect.h / 4 * (1), 22, 22};
            SDL_RenderCopy(app.renderer, buttonTextures.custumes, nullptr, &costom);
            text(app, costom.x + 22, costom.y + 5, u, "Medium12", {123, 131, 152, 255}, true);


        }
        else if (it.ID == SOUNDS_BUTTON) {
            roundedRectangleRGBA(app.renderer, 215 * app.W / 1503, it.rect.y, it.rect.w+it.rect.x, it.rect.y + 60, 10, 185, 193,
                                 209, 255);
            roundedBoxRGBA(app.renderer, 1 + 215 * app.W / 1503, it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10, 217,
                           227, 242, 255);
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, 1 + 215 * app.W / 1503, it.rect.y + 1, it.rect.w - 1, it.rect.y + 60, 10,
                               230, 240, 255, 255);

            }
            std::string u = "Sound";
            SDL_Rect sound = {it.rect.x + it.rect.w / 15, it.rect.y + it.rect.h / 2 - it.rect.h / 4 * (1), 22, 22};
            SDL_RenderCopy(app.renderer, buttonTextures.sounds, nullptr, &sound);
            text(app, sound.x + 22, sound.y + 5, u, "Medium12", {123, 131, 152, 255}, true);


        } else if (it.ID == GO_BUTTON) {
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.h+it.rect.y, 3, 216, 218, 249, 255);
            }
            SDL_Rect u={it.rect.x+4,it.rect.y+4,it.rect.w-8,it.rect.h-8};
            SDL_RenderCopy(app.renderer, buttonTextures.Go, nullptr,&u );
        }
        else if (it.ID == STOP_BUTTON){
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.h+it.rect.y, 3, 216, 218, 249, 255);
            }
            SDL_Rect u={it.rect.x+3,it.rect.y+3,28,28};
            SDL_RenderCopy(app.renderer, buttonTextures.Stop, nullptr,&u ); }
        else if (it.ID == FULLSCREEN_BUTTON) {
            roundedBoxRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.h+it.rect.y, 3, 255, 255, 255, 255);
            roundedRectangleRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.h+it.rect.y, 3,185,193,206,255);
            SDL_Rect u={it.rect.x+4,it.rect.y+4,it.rect.w-8,it.rect.h-8};
            SDL_RenderCopy(app.renderer, buttonTextures.Fullscreen, nullptr,&u );
        }


    }
    SDL_SetRenderTarget(app.renderer,nullptr);



}
void UpdateSprite (Sprite& s){
    s.scratchX+= s.dx;
    s.scratchY+= s. dy;

}
void RenderStage(AppState & app, Stage &stage,Sprite s ){
    int X=-s.w/2+app.W*1223/1503+s.scratchX;
    int Y=-s.h/2+app.H*228/609-s.scratchY;
    SDL_Rect u={X,Y,int(s.w),int(s.h)};




        SDL_RenderCopyEx(app.renderer,s.texture, nullptr,&u,s.angle, nullptr,SDL_FLIP_NONE);

}






