#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <c++/iostream>

#include <map>
#include <string>
#include "tinyfiledialogs.h"

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


//------------------ sprite names
constexpr int gorbaFront=100;
constexpr int gorbaBack=101;


constexpr int normal=2000;
constexpr int loop=2001;
constexpr int start=2002;


// 30 baray har page yeki dar mian

constexpr int move=200;
constexpr int turnRDegrees=202;
constexpr int turnLDegrees=204;
constexpr int goToRandomPosition=206;
constexpr int goToMousePointer=208;
constexpr int goToXY=210;

constexpr int sayForSeconds=230;
constexpr int thinkForSeconds=232;
constexpr int setSizeTo=234;
constexpr int changeSizeBy=236;

constexpr int playSoundMeow=260;
constexpr int startSoundMeow=262;
constexpr int stopAllSounds=264;
constexpr int changePitchaEfectBy=266;
constexpr int setPitchEffectTo=268;
constexpr int clearSoundEffects=270;
constexpr int changeVolumeBy=272;
constexpr int setVolumeTo=274;

constexpr int whenGreenFlagClicked=290;


// 320 loops
constexpr int  waitSecondes=320;
constexpr int  repeatHelper=321;
constexpr int repeat=322;


// 30 baray har page yeki dar mian magar text2

constexpr int moveTextInput=1000;
constexpr int turnRDegreesTextInput=1002;
constexpr int turnLDegreesTextInput=1004;
constexpr int goToXYTextInput1=1010;
constexpr int goToXYTextInput2=1011;


constexpr int sayForSecondsTextInput1=1030;
constexpr int sayForSecondsTextInput2=1031;
constexpr int thinkForSecondsTextInput1=1032;
constexpr int thinkForSecondsTextInput2=1033;
constexpr int setSizeToTextInput=1034;
constexpr int changeSizeByTextInput=1036;


constexpr int playSoundMeowTextInput=1060;
constexpr int startSoundMeowTextInput=1062;
constexpr int changePitchaEfectByTextInput1=1066;
constexpr int changePitchaEfectByTextInput2=1067;
constexpr int setPitchEffectToTextInput1=1068;
constexpr int setPitchEffectToTextInput2=1069;
constexpr int changeVolumeByTextInput=1072;
constexpr int setVolumeToTextInput=1074;

constexpr int  waitSecondesTextInput=1120;
constexpr int repeatTextInput=1122;


// structs
//// Mamad function

struct Box{
    float x=0,y=0;
    float angle=0;
    SDL_Texture* t= nullptr;
    float w=95,h=100;
    float scale=1;
    bool stop=false;

};
struct Children{
    int index;
    int ID;
    int type;
    int indexParents;
    SDL_Rect rect;
    SDL_Rect rectText1={0,0,0,0};
    SDL_Rect rectText2={0,0,0,0};

    std::string p1="";
    std::string p2="";
};
struct Block{
    int index;
    int ID;
    int type;

    SDL_Rect rect;
    SDL_Rect rectText1={0,0,0,0};
    SDL_Rect rectText2={0,0,0,0};

    std::vector<Children> child;   // loops
    std::string p1="";
    std::string p2="";

    std::string image;
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

    bool isTyping=false;
    bool isOnTextInput=false;
    bool isOnBlock=false;
    int IDTextInput;

    SDL_Cursor* cursorArrow= nullptr;
    SDL_Cursor* cursorIBeam= nullptr;
    SDL_Cursor* cursorHand= nullptr;

    //texture

    std::map<int,SDL_Texture*> texture;

    // Code Tab
    // در صورت بروز مشکل برای عوض کردن تب ها این بخش چک بشه
    bool activeCodePage[9]= {};
    std::map<std::string,TTF_Font*> font;
    std::vector<Block> block;
    std::vector<Block> allblock;
    bool pressedBlock=false;
    bool inWorkSpace=false;
    Block blockHelper;
    Block drawBlockHelper;
    Children childHelper;
    SDL_Rect workSpace;
    int deltaXMouseBlock;
    int deltaYMouseBlock;
    int offsetX1, offsetY1, offsetX2, offsetY2;

    // gorbe Texture

    Box box;
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

    bool pressedBlock=false;
};
struct ButtonRect{
    int ID;
    const SDL_Rect rect;
    std::string text="";   //only for TextBox

    bool active=true;
    bool charText=false;

    bool onButton=false;
    bool rightClick=false;
    bool leftClick=false;
    bool rightPressed=false;
    bool leftPressed=false;




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
    SDL_Color windowButtonMouse={122, 86, 199, 255};
    SDL_Color minimizeButton={214,214,214,255};
    SDL_Color minimizeButtonMouse={122, 86, 199, 255};
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

//// Golab function

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
bool isMouseInRect(MouseState &mouse,const SDL_Rect &rect);

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

void RenderTextureCodeTab(std::vector<ButtonRect> &buttons,AppState &app,ThemeCodeTab &color,TabTexture &texture);
void RenderCodeTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeCodeTab &,TabTexture &tex,MouseState &mouse);
void active(int id,std:: vector<AllTabButtons> &tab,bool ac=true);
void text( AppState &app,int x,int y,std::string T,std::string F,SDL_Color color,bool xyNotMiddle=false);
void image(AppState &app,int x,int y,double scale,int id,bool xtMiddle=false,int readX=0,int readY=0,double readWScale=1,double readHScale=1);

int blockDistanceTest(MouseState &mouse,const Block &c,const std::vector<Block> &a);
void DrawBlock(AppState &app,Block &block);
void CheckIsTyping(AppState &app,std:: vector<AllTabButtons> &tab,MouseState &mouse);
void SetCursor(AppState &app);
void TextInput(AppState &app, std::vector<AllTabButtons> &tabs, SDL_Event &e,KeyboardButton &key);


//// Golab function

void RenderGeneralTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeGeneralTab &color);
void RenderTextureGeneral(std::vector<ButtonRect> buttons,AppState &app,ThemeGeneralTab &color,TabTexture& tabTexture,ButtonTextures &buttonTextures,std::vector<AllTabButtons> &tabs,MouseState &mouse,KeyboardButton &key);
SDL_Texture* LoadTexture(SDL_Renderer* renderer,const std::string& file);
ButtonTextures LoadAllButtonTexture(SDL_Renderer* renderer);
void DestroyButtonTexture(ButtonTextures &textures);
void UpdateSprite (Sprite& s);
void RenderStage(AppState & app, Box &box);
void Engine(AppState &app,std::vector<AllTabButtons> &tabs,MouseState &mouse,KeyboardButton &key);
void LoadBlockTexture(AppState &app);

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

    SDL_SetWindowFullscreen(app.window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_SetWindowFullscreen(app.window, 0);
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

    LoadBlockTexture(app);



    // Variable declaration
    int iconSize=40;
    int dis=44;
    std::vector<AllTabButtons> tabButtons = {
            {TAB_GENERAL,true ,  {     {CLOSE_BUTTON, SDL_Rect{app.W-app.W/30,0,app.W/30,app.H/25}},
                                         {WINDOW_BUTTON, SDL_Rect{app.W-app.W*2/30,0,app.W/30,app.H/25}},
                                         {MINIMIZED_BUTTON, SDL_Rect{app.W-app.W*3/30,0,app.W/30,app.H/25}},
                                         {FILE_BUTTON, SDL_Rect{0,0,app.W*91/1503,app.H*56/867}},
                                         {EDIT_BUTTON, SDL_Rect{app.W*91/1503,0,app.W*105/1503,app.H*56/867}},
                                         {SETTING_BUTTON, SDL_Rect{app.W*196/1503,0,app.W*120/1503,app.H*56/867}},
                                         {CODE_BUTTON, SDL_Rect{0,app.H*67/609,app.W*95/1503,app.H*25/609}},
                                         {COSTUMES_BUTTON, SDL_Rect{app.W*95/1503,app.H*67/609,app.W*110/1503,app.H*25/609}},
                                         {SOUNDS_BUTTON, SDL_Rect{app.W*205/1503,app.H*67/609,app.W*85/1503,app.H*25/609}},
                                         {GO_BUTTON, SDL_Rect{app.W*950/1503,app.H*61/609,25,25}},
                                         {STOP_BUTTON, SDL_Rect{app.W*983/1503,app.H*61/609,25,25}},
                                         {FULLSCREEN_BUTTON, SDL_Rect{app.W*1462/1503,app.H*61/609,app.W*33/1503,app.H*31/867}}}

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
                                         {WorkSpace, SDL_Rect{app.W*250/1365,app.H*90/559,app.W*853/1365-15*app.W/1365-app.W*250/1365,app.H-app.H*90/559}},
                                         {move, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 101, 38}},
                                         {turnRDegrees, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*1/610,128,38}},
                                         {turnLDegrees, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*2/610,128,38}},
                                         {goToRandomPosition, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*3/610,146,38}},
                                         {goToMousePointer, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*4/610,146,38}},
                                         {moveTextInput, SDL_Rect{app.W * 70 / 1365+37,app.H * 130 / 610+6,28,23},"10"},
                                         {turnRDegreesTextInput, SDL_Rect{app.W * 70 / 1365+51,app.H * 130 / 610+app.H*dis*1/610+6,28,23},"15"},
                                         {turnLDegreesTextInput, SDL_Rect{app.W * 70 / 1365+51,app.H * 130 / 610+app.H*dis*2/610+6,28,23},"15"},
                                         {goToXY, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*5/610,125,38}},
                                         {goToXYTextInput1, SDL_Rect{app.W*70/1365+47,app.H*130/610+app.H*dis*5/610+6,28,23},"0"},
                                         {goToXYTextInput2, SDL_Rect{app.W*70/1365+92,app.H*130/610+app.H*dis*5/610+6,28,23},"0"},
                                         {sayForSeconds, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 161, 38},"",false},
                                         {thinkForSeconds, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*1/610,163,38},"",false},
                                         {changeSizeBy, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*2/610,116,38},"",false},
                                         {setSizeTo, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*3/610,107,38},"", false},
                                         {sayForSecondsTextInput1, SDL_Rect{app.W * 70 / 1365+34, app.H * 130 / 610+6, 28,23},"Hello!",false,true},
                                         {sayForSecondsTextInput2, SDL_Rect{app.W * 70 / 1365+100, app.H * 130 / 610+6, 28,23},"2",false},
                                         {thinkForSecondsTextInput1, SDL_Rect{app.W*70/1365+34,app.H*130/610+app.H*dis*1/610+6, 28,23},"Hello!",false,true},
                                         {thinkForSecondsTextInput2, SDL_Rect{app.W*70/1365+100,app.H*130/610+app.H*dis*1/610+6, 28,23},"2",false},
                                         {changeSizeByTextInput, SDL_Rect{app.W*70/1365+83,app.H*130/610+app.H*dis*2/610+6, 28,23},"10",false},
                                         {setSizeToTextInput, SDL_Rect{app.W*70/1365+58,app.H*130/610+app.H*dis*3/610+6, 28,23},"100",false},
                                         {playSoundMeow, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 178, 38},"",false},
                                         {startSoundMeow, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*1/610,127,38},"",false},
                                         {stopAllSounds, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*2/610,83,38},"",false},
                                         {changePitchaEfectBy, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*3/610,182,38},"", false},
                                         {setPitchEffectTo, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*dis*4/610, 165, 38},"",false},
                                         {clearSoundEffects, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*5/610,102,38},"",false},
                                         {changeVolumeBy, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*6/610,131,38},"",false},
                                         {setVolumeTo, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*7/610,123,38},"", false},
                                         {playSoundMeowTextInput, SDL_Rect{app.W * 70 / 1365+65, app.H * 130 / 610+6, 60, 20},"",false,true},
                                         {startSoundMeowTextInput, SDL_Rect{app.W*70/13656+65+50,app.H*130/610+app.H*dis*1/610+6+0,60,20},"",false,true},
                                         {changePitchaEfectByTextInput2, SDL_Rect{app.W*70/1365+150,app.H*130/610+app.H*dis*3/610+6,28,23},"10", false},
                                         {changePitchaEfectByTextInput1, SDL_Rect{app.W*70/1365+44,app.H*130/610+app.H*dis*3/610+7,52,23},"", false,true},
                                         {setPitchEffectToTextInput2, SDL_Rect{app.W * 70 / 1365+131, app.H * 130 / 610+app.H*dis*4/610+7, 28, 23},"100",false},
                                         {setPitchEffectToTextInput1, SDL_Rect{app.W * 70 / 1365+35, app.H * 130 / 610+app.H*dis*4/610+5, 52, 23},"",false,true},
                                         {changeVolumeByTextInput, SDL_Rect{app.W*70/1365+97,app.H*130/610+app.H*dis*6/610+5,28,23},"-10",false},
                                         {setVolumeToTextInput, SDL_Rect{app.W*70/1365+75,app.H*130/610+app.H*dis*7/610+5,28,23},"100", false},
                                         {whenGreenFlagClicked, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 97, 49},"",false},
                                         {waitSecondes, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 111, 38},"",false},
                                         {repeat, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*1/610,108,76},"",false},
                                         {waitSecondesTextInput, SDL_Rect{app.W * 70 / 1365+31, app.H * 130 / 610+6, 28, 23},"1",false},
                                         {repeatTextInput, SDL_Rect{app.W*70/1365+42,app.H*130/610+app.H*dis*1/610+7,28,23},"10",false}
            }
            }};

    Stage stage;
    Sprite gorba{gorbaFront,0, 0,100,100, LoadTexture(app.renderer,"icons/gorba(1).png"),0,0,0};


    app.box.t=LoadTexture(app.renderer,"icons/gorba(1).png");


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
    app.cursorArrow = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    app.cursorIBeam = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
    app.cursorHand  = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);

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
            TextInput(app,tabButtons,e,keyboardButton);
        }
        CheckIsTyping(app,tabButtons,mouse);
        keyboardButtonActions(keyboardButton,app,tabButtons);
        RenderTextureGeneral(tabButtons[0].buttons,app,ColorGeneral,tabTexture,buttonTextures,tabButtons,mouse,keyboardButton);
        SDL_RenderCopy(app.renderer,tabTexture.general, nullptr, nullptr);
        AllTabButtonActions(tabButtons,app,color,texture,mouse);
        RenderStage(app,app.box);

        SetCursor(app);
        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }



    SDL_DestroyTexture(tabTexture.general);
    DestroyButtonTexture(buttonTextures);



    SDL_FreeCursor(app.cursorArrow);
    SDL_FreeCursor(app.cursorIBeam);
    SDL_FreeCursor(app.cursorHand);

    SDL_DestroyTexture(app.box.t);
    SDL_DestroyTexture(app.textureHelperImage);
    SDL_DestroyTexture(app.textureHelperText);
    for(auto &it:app.font)
    {
        TTF_CloseFont(it.second);
    }
    for(auto &it:app.texture)
    {
        SDL_DestroyTexture(it.second);
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

bool isMouseInRect(MouseState &mouse,const SDL_Rect &rect)
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
    if((key.pressed[SDL_SCANCODE_LALT] || key.pressed[SDL_SCANCODE_RALT]) && key.pressed[SDL_SCANCODE_F4])
    {
        app.endProgram=true;
    }
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
void RenderCodeTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeCodeTab &color,TabTexture &texture,MouseState &mouse)
{
    for(auto &it:buttons)
    {
        if(0<=it.ID && it.ID<=8 && it.leftClick)
        {
            memset(app.activeCodePage,0,sizeof(app.activeCodePage));
            app.activeCodePage[it.ID]=true;
            for(auto &it2:buttons)
            {
                if(it.ID*30+200<=it2.ID && it2.ID<it.ID*30+200+30)
                    it2.active=true;
                else if(200<=it2.ID && it2.ID<=500)
                    it2.active=false;
                if(it.ID*30+1000<=it2.ID && it2.ID<it.ID*30+1000+30)
                    it2.active=true;
                else if(1000<=it2.ID && it2.ID<=1500)
                    it2.active=false;
            }
            RenderTextureCodeTab(buttons,app,color,texture);
            break;
        }
    }

    SDL_RenderCopy(app.renderer,texture.code,NULL,NULL);

    if(!app.allblock.empty())
    {
        for(auto &it:app.allblock)
        {
           DrawBlock(app,it);
        }
    }
    if(!app.block.empty())
    {
        for(auto &it:app.block)
        {
            DrawBlock(app,it);
        }
    }

    for(auto &it:buttons)
    {
        if(it.ID==WorkSpace)
        {
            if(it.onButton)
                app.inWorkSpace= true;
            else
                app.inWorkSpace=false;
            app.workSpace=it.rect;
        }
    }

    for(auto &it:buttons)
    {
        if(1000 <= it.ID && it.ID <= 1500 && it.active)
        {
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,it.text,"Roman13",SDL_Color{87, 94, 117,255});
        }
    }

    app.isOnBlock=false;

    for(auto &it:buttons)
    {
        if(it.ID<=MyBlocks && Motion<=it.ID)
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

        if(200 <= it.ID && it.ID <= 500 && it.active)
        {
            if(it.onButton)
            {
                app.isOnBlock=true;
            }
            if(it.leftPressed)
            {
                app.pressedBlock=true;
                app.blockHelper.ID=it.ID;
                app.blockHelper.type=normal;
                if(it.ID==322 || it.ID==324)
                    app.blockHelper.type=loop;
                if(290<=it.ID && it.ID<320)
                    app.blockHelper.type=start;
                app.blockHelper.index=app.block.size()-1;
                app.blockHelper.rect.w=it.rect.w;
                app.blockHelper.rect.h=it.rect.h;

                app.blockHelper.rectText1 = {0,0,0,0};
                app.blockHelper.rectText2 = {0,0,0,0};
                for(auto &it2:buttons)
                {
                    if(it2.ID==app.blockHelper.ID+800)
                    {
                        app.blockHelper.p1=it2.text;
                        app.blockHelper.rectText1=it2.rect;
                    }
                    if(it2.ID==app.blockHelper.ID+801)
                    {
                        app.blockHelper.p2=it2.text;
                        app.blockHelper.rectText2=it2.rect;
                    }
                }
                app.deltaXMouseBlock = mouse.xLeftDown - it.rect.x;
                app.deltaYMouseBlock = mouse.yLeftDown - it.rect.y;
                app.blockHelper.rect.x=mouse.x-app.deltaXMouseBlock;
                app.blockHelper.rect.y=mouse.y-app.deltaYMouseBlock;
                if(app.blockHelper.rectText1.w != 0)
                {
                    app.offsetX1 = app.blockHelper.rectText1.x - it.rect.x;
                    app.offsetY1 = app.blockHelper.rectText1.y - it.rect.y;
                }
                if(app.blockHelper.rectText2.w != 0)
                {
                    app.offsetX2 = app.blockHelper.rectText2.x - it.rect.x;
                    app.offsetY2 = app.blockHelper.rectText2.y - it.rect.y;
                }

                if (app.blockHelper.rectText1.w != 0)
                {
                    app.blockHelper.rectText1.x = app.blockHelper.rect.x + app.offsetX1;
                    app.blockHelper.rectText1.y = app.blockHelper.rect.y +  app.offsetY1 ;
                }
                if (app.blockHelper.rectText2.w != 0)
                {
                    app.blockHelper.rectText2.x = app.blockHelper.rect.x +  app.offsetX2;
                    app.blockHelper.rectText2.y = app.blockHelper.rect.y +   app.offsetY2;
                }


                DrawBlock(app,app.blockHelper);


            }
            if( app.pressedBlock && mouse.leftUp)
            {
                if(mouse.x-app.deltaXMouseBlock+app.blockHelper.rect.w<=app.workSpace.x+app.workSpace.w && app.workSpace.x<=mouse.x-app.deltaXMouseBlock && mouse.y-app.deltaYMouseBlock+app.blockHelper.rect.h<=app.workSpace.y+app.workSpace.h && app.workSpace.y<=mouse.y-app.deltaYMouseBlock)
                    {
                        if(blockDistanceTest(mouse,app.blockHelper,app.block)==1 && (app.blockHelper.type==loop || app.blockHelper.type==normal))
                        {
                            app.blockHelper.rect.x=app.block[app.block.size()-1].rect.x;
                            app.blockHelper.rect.y=app.block[app.block.size()-1].rect.y+app.block[app.block.size()-1].rect.h-6;
                            if (app.blockHelper.rectText1.w != 0) {
                                app.blockHelper.rectText1.x = app.blockHelper.rect.x + app.offsetX1;
                                app.blockHelper.rectText1.y = app.blockHelper.rect.y + app.offsetY1;
                            }
                            if (app.blockHelper.rectText2.w != 0) {
                                app.blockHelper.rectText2.x = app.blockHelper.rect.x + app.offsetX2;
                                app.blockHelper.rectText2.y = app.blockHelper.rect.y + app.offsetY2;
                            }
                            app.block.push_back(app.blockHelper);
                         //   app.allblock.push_back(app.blockHelper);
                        }
                        else if(blockDistanceTest(mouse,app.blockHelper,app.block)==2 && app.block[app.block.size()-1].type==loop && app.blockHelper.type==normal)
                        {
                            if(app.block[app.block.size()-1].child.empty())
                            {
                                app.blockHelper.rect.x=app.block[app.block.size()-1].rect.x+11;
                                app.blockHelper.rect.y=app.block[app.block.size()-1].rect.y+33;
                                if (app.blockHelper.rectText1.w != 0) {
                                    app.blockHelper.rectText1.x = app.blockHelper.rect.x + app.offsetX1;
                                    app.blockHelper.rectText1.y = app.blockHelper.rect.y + app.offsetY1;
                                }
                                if (app.blockHelper.rectText2.w != 0) {
                                    app.blockHelper.rectText2.x = app.blockHelper.rect.x + app.offsetX2;
                                    app.blockHelper.rectText2.y = app.blockHelper.rect.y + app.offsetY2;
                                }

                                app.childHelper.rect=app.blockHelper.rect;
                                app.childHelper.rectText1=app.blockHelper.rectText1;
                                app.childHelper.rectText2=app.blockHelper.rectText2;
                                app.childHelper.p1=app.blockHelper.p1;
                                app.childHelper.p2=app.blockHelper.p2;
                                app.childHelper.ID=app.blockHelper.ID;
                                app.childHelper.indexParents=app.block[app.block.size()-1].index;
                                app.childHelper.index=app.block[app.block.size()-1].child.size()-1;

                                app.block[app.block.size()-1].rect.h=87;

                                app.block[app.block.size()-1].child.push_back(app.childHelper);
                           //     app.allblock[ app.allblock.size()-1].child.push_back(app.childHelper);
                              //  app.allblock.push_back(app.blockHelper);
                            }
                            else
                            {
                                app.blockHelper.rect.x=app.block[app.block.size()-1].child[app.block[app.block.size()-1].child.size()-1].rect.x;
                                app.blockHelper.rect.y=app.block[app.block.size()-1].child[app.block[app.block.size()-1].child.size()-1].rect.y+app.block[app.block.size()-1].child[app.block[app.block.size()-1].child.size()-1].rect.h-6;
                                if (app.blockHelper.rectText1.w != 0) {
                                    app.blockHelper.rectText1.x = app.blockHelper.rect.x + app.offsetX1;
                                    app.blockHelper.rectText1.y = app.blockHelper.rect.y + app.offsetY1;
                                }
                                if (app.blockHelper.rectText2.w != 0) {
                                    app.blockHelper.rectText2.x = app.blockHelper.rect.x + app.offsetX2;
                                    app.blockHelper.rectText2.y = app.blockHelper.rect.y + app.offsetY2;
                                }

                                app.childHelper.rect=app.blockHelper.rect;
                                app.childHelper.rectText1=app.blockHelper.rectText1;
                                app.childHelper.rectText2=app.blockHelper.rectText2;
                                app.childHelper.p1=app.blockHelper.p1;
                                app.childHelper.p2=app.blockHelper.p2;
                                app.childHelper.ID=app.blockHelper.ID;
                                app.childHelper.indexParents=app.block[app.block.size()-1].index;
                                app.childHelper.index=app.block[app.block.size()-1].child.size()-1;

                                app.block[app.block.size()-1].rect.h+=app.blockHelper.rect.h;

                                app.block[app.block.size()-1].child.push_back(app.childHelper);
                            //   app.allblock[app.allblock.size()-1-app.block[app.block.size()-1].child.size()].child.push_back(app.childHelper);
                             //   app.allblock.push_back(app.blockHelper);
                            }
                        }
                        else
                        {
                            app.blockHelper.rect.x=mouse.x-app.deltaXMouseBlock;
                            app.blockHelper.rect.y=mouse.y-app.deltaYMouseBlock;
                            if (app.blockHelper.rectText1.w != 0) {
                                app.blockHelper.rectText1.x = app.blockHelper.rect.x + app.offsetX1;
                                app.blockHelper.rectText1.y = app.blockHelper.rect.y + app.offsetY1;
                            }
                            if (app.blockHelper.rectText2.w != 0) {
                                app.blockHelper.rectText2.x = app.blockHelper.rect.x + app.offsetX2;
                                app.blockHelper.rectText2.y = app.blockHelper.rect.y + app.offsetY2;
                            }
                            app.allblock.push_back(app.blockHelper);
                            if(app.block.empty())
                            {
                                app.block.push_back(app.blockHelper);
                            }

                        }
                        app.pressedBlock=false;
                        DrawBlock(app,app.blockHelper);
                    }
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
    {
        if(Motion<=it.ID && it.ID<=MyBlocks)
        {

            if(app.activeCodePage[it.ID])
            {
                int texty=app.H*106/609;
                std::string textfont="Bold14";
                if(it.ID==Motion)
                {
                    text(app,app.W*70/1365,texty,"Motion",textfont,SDL_Color{87,94,117,255},true);
                }
                else if(it.ID==Looks)
                {
                    text(app,app.W*70/1365,texty,"Looks",textfont,SDL_Color{87,94,117,255},true);
                }
                else if(it.ID==Sound)
                {
                    text(app,app.W*70/1365,texty,"Sound",textfont,SDL_Color{87,94,117,255},true);
                }
                else if(it.ID==Events)
                {
                    text(app,app.W*70/1365,texty,"Events",textfont,SDL_Color{87,94,117,255},true);
                }
                else if(it.ID==Control)
                {
                    text(app,app.W*70/1365,texty,"Control",textfont,SDL_Color{87,94,117,255},true);
                }
                else if(it.ID==Sensing)
                {
                    text(app,app.W*70/1365,texty,"Sensing",textfont,SDL_Color{87,94,117,255},true);
                }
                else if(it.ID==Operators)
                {
                    text(app,app.W*70/1365,texty,"Operators",textfont,SDL_Color{87,94,117,255},true);
                }
                else if(it.ID==Variables)
                {
                    text(app,app.W*70/1365,texty,"Variables",textfont,SDL_Color{87,94,117,255},true);
                }
                else if(it.ID==MyBlocks)
                {
                    text(app,app.W*70/1365,texty,"MyBlocks",textfont,SDL_Color{87,94,117,255},true);
                }
                SDL_SetRenderDrawColor(app.renderer,color.leftButtonClicked.r,color.leftButtonClicked.g,color.leftButtonClicked.b,color.leftButtonClicked.a);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }
            filledCircleRGBA(app.renderer,it.rect.w/2,it.rect.y+app.H*17/609,app.H*8.5/609-1,color.circle[it.ID].r,color.circle[it.ID].g,color.circle[it.ID].b,color.circle[it.ID].a);
            aacircleRGBA(app.renderer,it.rect.w/2,it.rect.y+app.H*17/609,app.H*8.5/609,color.circle[it.ID].r,color.circle[it.ID].g,color.circle[it.ID].b,color.circle[it.ID].a);
            aacircleRGBA(app.renderer,it.rect.w/2,it.rect.y+app.H*17/609,app.H*8.5/609-1,color.circle[it.ID].r,color.circle[it.ID].g,color.circle[it.ID].b,color.circle[it.ID].a);
            aacircleRGBA(app.renderer,it.rect.w/2,it.rect.y+app.H*17/609,app.H*8.5/609,color.circleBorder[it.ID].r,color.circleBorder[it.ID].g,color.circleBorder[it.ID].b,color.circleBorder[it.ID].a);

        }
        if(200 <= it.ID && it.ID <= 500)
        {
            if(it.active)
                image(app,it.rect.x,it.rect.y,1,it.ID);
        }
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
void image(AppState &app,int x,int y,double scale,int id,bool xyMiddle,int readX,int readY,double readWScale,double readHScale)
{
    if(app.texture.find(id)==app.texture.end())
    {
        std::cout<<"Error, texture not found in map"<<std::endl;
        app.endProgram=true;
        return;
    }
    int imageW,imageH;
    SDL_QueryTexture(app.texture[id],NULL,NULL,&imageW,&imageH);
    SDL_Rect rect;
    SDL_Rect scr;
    scr.x=readX;
    scr.y=readY;
    scr.w=readX+(double)imageW*readWScale>imageW ? imageW-readX:(double)imageW*readWScale;
    scr.h=readY+(double)imageH*readHScale>imageH ? imageH-readY:(double)imageH*readHScale;
    if(xyMiddle)
    {
        rect.x=x-(double)imageW/scale/2.0;
        rect.y=y-(double)imageH/scale/2.0;
        rect.w=(double)scr.w/scale;
        rect.h=(double)scr.h/scale;
    }
    else
    {
     rect.x=x;
    rect.y=y;
    rect.w=(double)scr.w/scale;
    rect.h=(double)scr.h/scale;
    }


    if(readX>imageW || readY>imageH)
    {
        std::cout<<"Eror , out of renge of image"<<std::endl;
        return;
    }

    SDL_RenderCopy(app.renderer,app.texture[id],&scr,&rect);
}
int blockDistanceTest(MouseState &mouse,const Block &c,const std::vector<Block> &a)
{
    if(a.size()!=0)
    {
        SDL_Rect b={mouse.x-(mouse.xLeftDown-c.rect.x),mouse.y-(mouse.yLeftDown-c.rect.y),c.rect.w,c.rect.h};
        SDL_Rect ar=a[a.size()-1].rect;
        bool a1=mouse.y-ar.y-ar.h>=0 && 100>=mouse.y-ar.y-ar.h;
        bool a2=mouse.x-ar.x>=-30 && mouse.x-ar.x-ar.w<=30;
        bool a3=mouse.y-ar.y-ar.h<0 && 100>=mouse.y-ar.y-ar.h;
        if(a1 && a2)
            return 1;
        if(a3 && a2)
            return 2;
    }
    return 0;
}
void CheckIsTyping(AppState &app,std:: vector<AllTabButtons> &tab,MouseState &mouse)
{
    app.isOnTextInput=false;
    for(auto it1:tab)
        if(it1.active)
            for(auto it2:it1.buttons)
            {
                if(1000<=it2.ID && it2.ID<=1500 && it2.active)
                {
                    if(it2.onButton)
                    {
                        app.isOnTextInput=true;
                        if(it2.active && it2.leftClick)
                        {
                            app.IDTextInput=it2.ID;
                            SDL_StartTextInput();
                            it2.text="";
                            app.isTyping=true;
                        }
                    }
                }
            }

    if(app.isTyping)
    {
        if(mouse.leftDown && !app.isOnTextInput)
        {
            SDL_StopTextInput();
            app.isTyping=false;
        }
    }
}
void SetCursor(AppState &app)
{
    if(app.isOnTextInput)
    {
        SDL_SetCursor(app.cursorIBeam);
    }
    else if(app.isOnBlock && !app.isOnTextInput)
    {
        SDL_SetCursor(app.cursorHand);
    }
    else
    {
        SDL_SetCursor(app.cursorArrow);
    }

}
void TextInput(AppState &app, std::vector<AllTabButtons> &tabs, SDL_Event &e,KeyboardButton &key)
{
    if(!app.isTyping)
        return;
    ButtonRect* activeBtn = nullptr;
    for (auto &tab : tabs) {
        if (!tab.active) continue;
        for (auto &btn : tab.buttons) {
            if (btn.ID == app.IDTextInput) {
                activeBtn = &btn;
                break;
            }
        }
    }
    if (!activeBtn)
        return;

        if (e.type == SDL_TEXTINPUT)
        {
            if(activeBtn->charText)
            {
                activeBtn->text += e.text.text;
            }
            else
            {
                if (isdigit(e.text.text[0]) || e.text.text[0] == '-')
                {
                    activeBtn->text += e.text.text;
                }
            }

        }
        if(key.keyDown[SDL_SCANCODE_BACKSPACE])
            if (!activeBtn->text.empty())
            {
                activeBtn->text.pop_back();
            }
    if (key.keyDown[SDL_SCANCODE_RETURN])
    {
        app.isTyping = false;
        app.IDTextInput = -1;
        SDL_StopTextInput();
    }
}
void DrawBlock(AppState &app,Block &block)
{
 //   std::cout<<block.child.size()<<std::endl;
    if(block.type==loop && block.child.size()!=0)
    {
        image(app,block.rect.x,block.rect.y,1,block.ID,false,0,0,1,37.0/76.0);
        for(int i=0;i<block.child.size();i++)
        {
            image(app,block.rect.x,block.rect.y+36+i*30,1,repeatHelper);
        }
        image(app,block.rect.x,block.rect.y+35+(block.child.size())*30,1,block.ID,false,0,47,1,1);
        for(auto it:block.child)
        {
            app.drawBlockHelper.ID=it.ID;
            app.drawBlockHelper.rect=it.rect;
            app.drawBlockHelper.rectText1=it.rectText1;
            app.drawBlockHelper.rectText2=it.rectText2;
            app.drawBlockHelper.p1=it.p1;
            app.drawBlockHelper.p2=it.p2;
            app.drawBlockHelper.type=it.type;
            DrawBlock(app,app.drawBlockHelper);
        }
    }
    else
    {
        image(app,block.rect.x,block.rect.y,1,block.ID);
    }
    if(block.rectText1.w != 0)
         text(app,block.rectText1.x+block.rectText1.w/2,block.rectText1.y+block.rectText1.h/2,block.p1,"Roman13",SDL_Color{87, 94, 117,255});
    if(block.rectText2.w != 0)
        text(app,block.rectText2.x+block.rectText2.w/2,block.rectText2.y+block.rectText2.h/2,block.p2,"Roman13",SDL_Color{87, 94, 117,255});
}
void LoadBlockTexture(AppState &app)
{
    app.texture[move]=LoadTexture(app.renderer,"blocks/move.png");
    app.texture[turnRDegrees]=LoadTexture(app.renderer,"blocks/turnRDegrees.png");
    app.texture[turnLDegrees]=LoadTexture(app.renderer,"blocks/turnLDegrees.png");
    app.texture[goToRandomPosition]=LoadTexture(app.renderer,"blocks/goToRandomPosition.png");
    app.texture[goToMousePointer]=LoadTexture(app.renderer,"blocks/goToMousePointer.png");
    app.texture[goToXY]=LoadTexture(app.renderer,"blocks/goToXY.png");
    app.texture[sayForSeconds]=LoadTexture(app.renderer,"blocks/sayForSeconds.png");
    app.texture[thinkForSeconds]=LoadTexture(app.renderer,"blocks/thinkForSeconds.png");
    app.texture[setSizeTo]=LoadTexture(app.renderer,"blocks/setSizeTo.png");
    app.texture[changeSizeBy]=LoadTexture(app.renderer,"blocks/changeSizeBy.png");
    app.texture[playSoundMeow]=LoadTexture(app.renderer,"blocks/playSoundMeow.png");
    app.texture[startSoundMeow]=LoadTexture(app.renderer,"blocks/startSoundMeow.png");
    app.texture[stopAllSounds]=LoadTexture(app.renderer,"blocks/stopAllSounds.png");
    app.texture[changePitchaEfectBy]=LoadTexture(app.renderer,"blocks/changePitchaEfectBy.png");
    app.texture[setPitchEffectTo]=LoadTexture(app.renderer,"blocks/setPitchEffectTo.png");
    app.texture[clearSoundEffects]=LoadTexture(app.renderer,"blocks/clearSoundEffects.png");
    app.texture[changeVolumeBy]=LoadTexture(app.renderer,"blocks/changeVolumeBy.png");
    app.texture[setVolumeTo]=LoadTexture(app.renderer,"blocks/setVolumeTo.png");
    app.texture[whenGreenFlagClicked]=LoadTexture(app.renderer,"blocks/whenGreenFlagClicked.png");
    app.texture[waitSecondes]=LoadTexture(app.renderer,"blocks/waitSecondes.png");
    app.texture[repeat]=LoadTexture(app.renderer,"blocks/repeat.png");
    app.texture[repeatHelper]=LoadTexture(app.renderer,"blocks/repeatHelper.png");

}
//// Golab function

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
                {
                    const SDL_MessageBoxButtonData buttons[] = {

                            { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "No" },
                            { SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Yes" }
                    };

                    const SDL_MessageBoxData messageboxdata = {
                            SDL_MESSAGEBOX_INFORMATION,
                            app.window,
                            "Exit Program",
                            "Are you sure you want to exit? Any unsaved changes will be lost.",
                            SDL_arraysize(buttons),
                            buttons,
                            NULL
                    };

                    int buttonid;
                    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) == 0)
                    {
                        if (buttonid == 1)
                        {
                            app.endProgram = true;
                        }
                    }
//                    int choice = tinyfd_messageBox(
//                            "Exit Program",
//                            "Are you sure you want to exit? Any unsaved changes will be lost.",
//                            "yesno",
//                            "question",
//                            1
//                    );
//                    if (choice == 1) { // اگر کاربر Yes را انتخاب کرد
//                        app.endProgram = true;
//                    }
                }
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
            //    if(it.leftClick)

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
    textures.Go= LoadTexture(renderer,"icons/Go1.png");
    textures.Stop= LoadTexture(renderer,"icons/Stop2.png");
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
void RenderTextureGeneral(std::vector<ButtonRect> buttons,AppState &app,ThemeGeneralTab &color,TabTexture& tabTexture,ButtonTextures &buttonTextures,std::vector<AllTabButtons> &tabs,MouseState &mouse,KeyboardButton &key){
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
            roundedRectangleRGBA(app.renderer, 205 * app.W / 1503, it.rect.y, it.rect.w+it.rect.x, it.rect.y + 60, 10, 185, 193,209, 255);
            roundedBoxRGBA(app.renderer, 1 + 205 * app.W / 1503, it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10, 217,227, 242, 255);
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, 1 + 205 * app.W / 1503, it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10,230, 240, 255, 255);

           }
           std::string u = "Sound";
           SDL_Rect sound = {it.rect.x + it.rect.w / 15, it.rect.y + it.rect.h / 2 - it.rect.h / 4 * (1), 22, 22};
            SDL_RenderCopy(app.renderer, buttonTextures.sounds, nullptr, &sound);
            text(app, sound.x + 22, sound.y + 5, u, "Medium12", {123, 131, 152, 255}, true);


        }
        else if (it.ID == GO_BUTTON) {
            if (it.onButton)
            {
                roundedBoxRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.h+it.rect.y, 3, 216, 218, 249, 255);
            }
            if(it.leftClick)
            {
                Engine(app,tabs,mouse,key);
            }
            SDL_Rect u={it.rect.x+4,it.rect.y+4,20,20};
            SDL_RenderCopy(app.renderer, buttonTextures.Go, nullptr,&u );
        }
        else if (it.ID == STOP_BUTTON){
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.h+it.rect.y, 3, 216, 218, 249, 255);
            }
            SDL_Rect u={it.rect.x+3,it.rect.y+3,20,20};
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
void RenderStage(AppState & app, Box &box)
{
    int X=-box.w/2+app.W*1223/1503+box.x;
    int Y=-box.h/2+app.H*228/609-box.y;
    SDL_Rect u={X,Y,int(box.w),int(box.h)};

    SDL_RenderCopyEx(app.renderer,box.t, nullptr,&u,box.angle, nullptr,SDL_FLIP_NONE);

}
void Engine(AppState &app,std::vector<AllTabButtons> &tabs,MouseState &mouse,KeyboardButton &key)
{
    std::cout<<"run";
    SDL_Event e;
    SDL_PollEvent(&e);
    for(auto &it:app.block)
    {
           SDL_PollEvent(&e);

           if(it.ID==move)
           {
               app.box.x+=std::stoi(it.p1)*cos(app.box.angle*M_PI/180.0);
               app.box.y+=std::stoi(it.p1)*sin(app.box.angle*M_PI/180.0);
           }
           else if(it.ID==turnRDegrees)
           {
               app.box.angle-=std::stoi(it.p1);
           }
           else if(it.ID==turnRDegrees)
           {
               app.box.angle+=std::stoi(it.p1);
           }


      //  RenderStage(app,app.box);
        SDL_RenderPresent(app.renderer);
            resetKeyboardButtons(key);
            resetButtonRect(tabs);
            resetMouseState(mouse);
            while(SDL_PollEvent(&e))
            {
                updateKeyboardButtons(key,e);
                updateButtonRectAndMouseState(mouse,tabs,e);
            }
    }
}




