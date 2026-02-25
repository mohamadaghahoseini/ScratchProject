#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <c++/iostream>

#include <map>
#include <string>
#include "tinyfiledialogs.h"
#include "json.hpp"
#include <windows.h>
using json = nlohmann::json;

//   Button names
constexpr int CLOSE_BUTTON=27;
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

constexpr int  fileMenu=23;
constexpr int   fileNew=24;
constexpr int   fileSave=25;
constexpr int   fileLoad=26;

constexpr int   stageBackground=36;
constexpr int   backgroundGallery=37;
//constexpr int   uploadBackground=38;
constexpr int   setBackground=39;

constexpr int   spriteState=40;

constexpr int   showButton=41;
constexpr int   showButtonActive=42;
constexpr int   hideButton=43;
constexpr int   hideButtonActive=44;

constexpr int   nameSpriteTextInput=4041;
constexpr int   xSpriteTextInput=4042;
constexpr int   ySpriteTextInput=4043;
constexpr int   sizeSpriteTextInput=4044;
constexpr int   directionSpriteTextInput=4045;



// tab names
constexpr int TAB_GENERAL=12;
constexpr int TAB_CODE=13;
constexpr int TAB_COSTUMES=14;
constexpr int TAB_SOUNDS=15;
constexpr int TAB_EXTENSION=32;
constexpr int TAB_GALLERY=45;

constexpr int Motion=0;
constexpr int Looks=1;
constexpr int Sound=2;
constexpr int Events=3;
constexpr int Control=4;
constexpr int Sensing=5;
constexpr int Operators=6;
constexpr int Variables=7;
constexpr int MyBlocks=8;
constexpr int Pen=9;

constexpr int WorkSpace=17;
constexpr int Extension=28;
constexpr int PenExtension=29;
constexpr int BackExtension=30;
constexpr int PenPhoto=31;
constexpr int CLOSE_BUTTONExtension=33;
constexpr int WINDOW_BUTTONExtension=34;
constexpr int MINIMIZED_BUTTONExtension=35;


constexpr int BackGallery=45;
constexpr int CLOSE_BUTTONGallery=46;
constexpr int WINDOW_BUTTONGallery=47;
constexpr int MINIMIZED_BUTTONGallery=48;
constexpr int uploadBackground=51;

//------------------ sprite names
constexpr int gorbaFront=100;
constexpr int gorbaBack=101;
constexpr int gorbaStandard=102;

constexpr int normal=2000;
constexpr int loop=2001;
constexpr int loopInfinity=2002;
constexpr int start=2003;


// 30 baray har page yeki dar mian
// Motion
constexpr int move=200;
constexpr int turnRDegrees=202;
constexpr int turnLDegrees=204;
constexpr int goToRandomPosition=206;
constexpr int goToMousePointer=208;
constexpr int goToXY=210;
constexpr int changeXBy=212;
constexpr int setXTo=214;
constexpr int changeYBy=216;
constexpr int setYTo=218;
//Looks
constexpr int sayForSeconds=230;
constexpr int say=232;
constexpr int thinkForSeconds=234;
constexpr int think=236;
constexpr int changeSizeBy=238;
constexpr int setSizeTo=240;
constexpr int show=242;
constexpr int hide=244;
constexpr int setColorEffect=246;
constexpr int setFishEye=248;
constexpr int setWhirlEffect=250;
constexpr int clearGraphicEffect=252;
// Sound
constexpr int playSoundMeow=260;
constexpr int startSoundMeow=262;
constexpr int stopAllSounds=264;
constexpr int changePitchaEfectBy=266;
constexpr int setPitchEffectTo=268;
constexpr int clearSoundEffects=270;
constexpr int changeVolumeBy=272;
constexpr int setVolumeTo=274;
//Events
constexpr int whenGreenFlagClicked=290;
constexpr int whenSpaceKeyPressed=292;
constexpr int whenThisSpriteClicked=294;
constexpr int whenIReceiveMassege1=296;
constexpr int broadcast=298;
constexpr int broadcastAndWait=300;



// 320 loops
//Controls
constexpr int  waitSecondes=320;
constexpr int  repeatHelper=321;
constexpr int repeat=322;
constexpr int forever =324;

//Sensing
constexpr int askAndWait=350;

//Operator 380

//Varaibles 410


//MyBlocks 440

// Pen 470
constexpr int eraseAll=470;
constexpr int stamp=472;
constexpr int penDown=474;
constexpr int penUp=476;
constexpr int setPenColorTo=478;
constexpr int setPenBrightnees=480;
constexpr int setPenSaturation=482;

constexpr int setPenColorToColorInput=4780;

// 30 baray har page yeki dar mian magar text2

constexpr int moveTextInput=1000;
constexpr int turnRDegreesTextInput=1002;
constexpr int turnLDegreesTextInput=1004;
constexpr int goToXYTextInput1=1010;
constexpr int goToXYTextInput2=1011;
constexpr int changeXByTextInput=1012;
constexpr int setXToTextInput=1014;
constexpr int changeYByTextInput=1016;
constexpr int setYToTextInput=1018;

constexpr int sayForSecondsTextInput1=1030;
constexpr int sayForSecondsTextInput2=1031;
constexpr int sayTextInput=1032;
constexpr int thinkForSecondsTextInput1=1034;
constexpr int thinkForSecondsTextInput2=1035;
constexpr int thinkTextInput=1036;
constexpr int setSizeToTextInput=1040;
constexpr int changeSizeByTextInput=1038;
constexpr int setColorEffectTextInput=1046;
constexpr int setFishEyeTextInput=1048;
constexpr int setWhirlEffectTextInput=1050;



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

constexpr int askAndWaitTextInput=1150;

constexpr int setPenBrightneesTextInput=1280;
constexpr int setPenSaturationTextInput=1282;

constexpr int nameCostume=3000;
constexpr int uploadImage=3001;
constexpr int xImage=3002;
constexpr int yImage=3003;
constexpr int sizeImage=3004;

constexpr int nameCostumeTextInput=3500;
constexpr int xImageTextInput=3501;
constexpr int yImageTextInput=3502;
constexpr int sizeImageTextInput=3503;

constexpr int flipHorizontal=3010;
constexpr int flipVertical=3011;
constexpr int deleteButton=3012;

constexpr int mouseButton=3013;
constexpr int eraser=3014;
constexpr int brush=3015;
constexpr int textOut=3016;
constexpr int lineS=3017;
constexpr int circle=3018;
constexpr int rectangle=3019;
constexpr int fill=3020;

constexpr int showSpace=3021;
constexpr int colorChose=3022;

constexpr int mouseButtonWhite=4013;
constexpr int eraserWhite=4014;
constexpr int brushWhite=4015;
constexpr int textOutWhite=4016;
constexpr int lineSWhite=4017;
constexpr int circleWhite=4018;
constexpr int rectangleWhite=4019;
constexpr int fillWhite=4020;

constexpr int costumeEditor=4021;
constexpr int backgroundEditor=4022;

constexpr int backgroundName=5000;
constexpr int save=5001;
constexpr int saveLibrary=5002;

constexpr int library1  = 10001;
constexpr int library2  = 10002;
constexpr int library3  = 10003;
constexpr int library4  = 10004;
constexpr int library5  = 10005;
constexpr int library6  = 10006;
constexpr int library7  = 10007;
constexpr int library8  = 10008;
constexpr int library9  = 10009;
constexpr int library10 = 10010;
constexpr int library11 = 10011;
constexpr int library12 = 10012;
constexpr int library13 = 10013;
constexpr int library14 = 10014;
constexpr int library15 = 10015;
constexpr int library16 = 10016;
constexpr int library17 = 10017;
constexpr int library18 = 10018;
constexpr int library19 = 10019;
constexpr int library20 = 10020;
constexpr int library21 = 10021;
constexpr int library22 = 10022;
constexpr int library23 = 10023;

// structs
//// Mamad function

struct UploadedImageCostume{
    SDL_Texture* texture;
    int w;
    int h;
    int x=0,y=0;
    int size=100;
    std::string path;
};
struct Box{
    float x=0,y=0;
    float angle=90;
    SDL_Texture* t= nullptr;
    SDL_Texture* background= nullptr;
    SDL_Texture* backgroundStage= nullptr;
    std::string backgroundName;
    float w=95,h=100;
    float scale=1;
    bool stop=false;
    bool isShowing=true;


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
    bool isrunning=false;


    SDL_Color color;
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
    bool isrunning=false;

    SDL_Color color;
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
    SDL_Texture* textureHelperCos= nullptr;

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
    bool activeCodePage[10]= {};
    std::map<std::string,TTF_Font*> font;
    std::map<int,bool> paint;
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
    Box boxhelper;
    bool inPaintSpace;
    int xPaint=0;
    int yPaint=0;
    SDL_Color colorPaint={153,102,255,255};
    bool isShaping=false;
    bool Confrim=false;
    int n=0;
    int xImage=0;
    int yImage=0;
    int sizeImage=100;
    std::vector<UploadedImageCostume> imageCos;
    SDL_Rect paintSpace;
    bool fileMenu=false;
    bool activeExtention=false;

    SDL_Color penColor={45,20,111,255};
    bool activeCosEdit=true;
    std::map<int,SDL_Texture*> library;
    std::map<int,std::string> libraryName;
    HANDLE hChange;
    //=-----------

    float boxh;
    float boxw;
    //=-----------
    bool engineRunning= false;
    int engineCurrentIndex=0;
    bool engineFinished=false;
    bool isWaiting=false;
    bool isPenDown= false;
    Uint32 waitStartTime=0;
    Uint32 waitDuration=0;
    Uint32 waitRemaining=0;
    SDL_Color pen={45,20,111,255};

    bool isRepeating=false;
    int  repeatBlockIndex=-1;
    // int  repeatEndIndex   = 0;
    int  repeatTotal      = 0;
    int  repeatCounter    = 0;
    int repeatInnerIndex=0;



    bool isSaying= false;
    std::string say="Hello!";
    SDL_Texture *saytexture;
    bool isThinking=false;
    SDL_Texture *thinktexture;
    std::string think="Hmm...";

    // Graphic Effects
    float colorEffect = 0;
    float brightnessEffect = 0;
    float ghostEffect=0;

    SDL_Surface* boxOriginalSurface = nullptr;
    SDL_Texture* boxEffectTexture = nullptr;
    float lastAppliedColorEffect = -999;
    SDL_Texture* boxBrightnessTexture = nullptr;
    float lastAppliedBrightnessEffect = -999;
    SDL_Texture* boxghostTexture = nullptr;
    float lastAppliedghostEffect = -999;
    SDL_Texture * penTexture;

    SDL_Rect stageRect;
    std::vector<std::string > LOG;

    int cycle=0;
    int logPrintedIndex = 0;


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

    SDL_Color topBar ={133,92,214,255};
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
bool stop=false;
bool go =false;



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
void AllTabButtonActions(std::vector<AllTabButtons> &tab,AppState &app,Theme &color,TabTexture &texture,MouseState &mouse,KeyboardButton &key,ButtonTextures buttonTextures);


void RenderTextureCodeTab(std::vector<ButtonRect> &buttons,AppState &app,ThemeCodeTab &color,TabTexture &texture);
void RenderCodeTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeCodeTab &,TabTexture &tex,MouseState &mouse,std::vector<AllTabButtons> &tab);
void active(int id,std:: vector<AllTabButtons> &tab,bool ac=true);
void text( AppState &app,int x,int y,std::string T,std::string F,SDL_Color color,bool xyNotMiddle=false);
void image(AppState &app,int x,int y,double scale,int id,bool xtMiddle=false,int readX=0,int readY=0,double readWScale=1,double readHScale=1,bool getTexture=false,SDL_Texture* t=nullptr);

int blockDistanceTest(MouseState &mouse,const Block &c,const std::vector<Block> &a);
void DrawBlock(AppState &app,Block &block);
void CheckIsTyping(AppState &app,std:: vector<AllTabButtons> &tab,MouseState &mouse);
void SetCursor(AppState &app);
void TextInput(AppState &app, std::vector<AllTabButtons> &tabs, SDL_Event &e,KeyboardButton &key);
void LoadMyTexture(AppState &app);
void RenderCostumesTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeCodeTab &color,TabTexture &texture,MouseState &mouse,std::vector<AllTabButtons> &tabs);
void textureRenderer(AppState &app,std::vector<AllTabButtons> &tabs,float x,float y,float scale);
std::string textureToBase64(SDL_Renderer* renderer, SDL_Texture* texture);
SDL_Texture* base64ToTexture(SDL_Renderer* renderer, const std::string& base64Str, int w, int h);
void SaveProject(AppState &app);
void LoadProject(AppState& app);
void RenderExtensionTab(std::vector<AllTabButtons> &tabs,std::vector<ButtonRect> &buttons,AppState &app,ThemeCodeTab &color,TabTexture &texture);
void UpdateSpriteState(std::vector<AllTabButtons> &tabs,AppState &app);
void RenderGalleryTab(std::vector<AllTabButtons> &tabs,std::vector<ButtonRect> &buttons,AppState &app,ThemeCodeTab &color,TabTexture &texture);
SDL_Texture* createRedTintedTexture(SDL_Renderer* renderer, SDL_Texture* texture);
void SetBackground(AppState &app, SDL_Texture* t1, SDL_Texture* t2);
void loadPNGLibrary(AppState &app);
bool LibraryChanged(AppState &app);

//// Golab function

void RenderGeneralTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeGeneralTab &color,MouseState &mouse,std::vector<AllTabButtons> &tabs);
void RenderTextureGeneral(std::vector<ButtonRect> buttons,AppState &app,ThemeGeneralTab &color,TabTexture& tabTexture,ButtonTextures &buttonTextures,std::vector<AllTabButtons> &tabs,MouseState &mouse,KeyboardButton &key);
SDL_Texture* LoadTexture(SDL_Renderer* renderer,const std::string& file);
ButtonTextures LoadAllButtonTexture(SDL_Renderer* renderer);
void DestroyButtonTexture(ButtonTextures &textures);
void UpdateSprite (Sprite& s);
void RenderStage(AppState & app, Box &box);
void Engine(AppState &app,std::vector<AllTabButtons> &tabs,MouseState &mouse,KeyboardButton &key);
double safeStod(const std::string &s, double defaultVal );
void executeBlock(AppState& app, Block & block,MouseState &mouse,int line,std::vector<AllTabButtons> &tabs);
void inverseRoundedBoxRGBA(SDL_Renderer* renderer,int x1, int y1, int x2, int y2,int radius,Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void rgbToHsv(Uint8 r, Uint8 g, Uint8 b, float &h, float &s, float &v);
void hsvToRgb(float h, float s, float v, Uint8 &r, Uint8 &g, Uint8 &b);
SDL_Color setBrightness(SDL_Color color, float amount);
SDL_Color setSaturation(SDL_Color color, float amount);
SDL_Texture* createHueShiftedTexture(SDL_Renderer* renderer,SDL_Surface* original,float colorEffect);
SDL_Texture* createGhostTexture(SDL_Renderer* renderer, SDL_Surface* original, float brightnessEffect);
SDL_Texture* createBrightnessTexture(SDL_Renderer* renderer,SDL_Surface* originalSurface,float brightness);
void pening(bool isp,AppState & app,int x1,int y1);
void clearPenTexture(AppState& app);
void Stamp(AppState& app);
void LogEvent(AppState&app,int line, const std::string& cmd, const std::string& inf);
void PrintLog(AppState &app);


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

   //  renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);   //SDL_RENDERER_ACCELERATED or SDL_RENDERER_SOFTWARE
    // Mamad
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
    app.renderer=renderer;
    ButtonTextures buttonTextures= LoadAllButtonTexture(app.renderer);

    LoadMyTexture(app);

    // Variable declaration
    int iconSize=40;
    int dis=44,diis=40,an=app.W*15/1350,libW=app.W*153/1350,libH=app.W*157/1350,libY=app.H*70/609,anY=app.W*15/1350;
    std::vector<AllTabButtons> tabButtons = {
            {TAB_GENERAL,true ,  {     {CLOSE_BUTTON, SDL_Rect{app.W-app.W/30,0,app.W/30,app.H/25}},
                                         {WINDOW_BUTTON, SDL_Rect{app.W-app.W*2/30,0,app.W/30,app.H/25}},
                                         {MINIMIZED_BUTTON, SDL_Rect{app.W-app.W*3/30,0,app.W/30,app.H/25}},
                                         {FILE_BUTTON, SDL_Rect{app.W*10/1365,0,app.W*80/1365,app.H*40/609}},
                                         {EDIT_BUTTON, SDL_Rect{app.W*208/1365,0,app.W*90/1365,app.H*40/609}},
                                         {SETTING_BUTTON, SDL_Rect{app.W*98/1365,0,app.W*105/1365,app.H*40/609}},
                                         {CODE_BUTTON, SDL_Rect{0,app.H*59/609,app.W*95/1365,app.H*35/609}},
                                         {COSTUMES_BUTTON, SDL_Rect{app.W*95/1365,app.H*58/609,app.W*110/1365,app.H*35/609}},
                                         {SOUNDS_BUTTON, SDL_Rect{app.W*205/1365,app.H*58/609,app.W*95/1365,app.H*35/609}},
                                         {GO_BUTTON, SDL_Rect{app.W*950/1503,app.H*61/609,25,25}},
                                         {STOP_BUTTON, SDL_Rect{app.W*983/1503,app.H*61/609,25,25}},
                                         {FULLSCREEN_BUTTON, SDL_Rect{app.W*1462/1503,app.H*61/609,app.W*33/1503,app.H*31/867}},
                                         {fileMenu, SDL_Rect{app.W*10/1365,app.H*40/609,app.W*188/1365,app.H*35*3/609}},
                                         {fileNew, SDL_Rect{app.W*10/1365,app.H*40/609+app.H*35*0/609,app.W*188/1365,app.H*35/609}},
                                         {fileSave, SDL_Rect{app.W*10/1365,app.H*40/609+app.H*35*1/609,app.W*188/1365,app.H*35/609}},
                                         {fileLoad, SDL_Rect{app.W*10/1365,app.H*40/609+app.H*35*2/609,app.W*188/1365,app.H*35/609}},
                                         {stageBackground, SDL_Rect{app.W * 1268 / 1350, app.H - app.H * 210 / 609, app.W * 73 / 1350, app.H * 210 / 609}},
                                         {backgroundGallery, SDL_Rect{app.W * 1282 / 1350, app.H - app.H * 49 / 609, app.H * 40 / 609, app.H * 40 / 609}},
                                         {setBackground, SDL_Rect{app.W*1240/1365,app.H*461/609+app.H*35*2/609,app.W*188/1365,app.H*35/609}},
                                         {spriteState, SDL_Rect{app.W*950/1503,app.H - app.H * 210 / 609,-app.W*965/1503+app.W * 1271 / 1350,app.H*90/609}},
                                         {xSpriteTextInput,SDL_Rect{app.W*950/1503+app.W * 233 / 1365, app.H * 411 / 609, app.W * 50 / 1365, app.H * 28 / 609},"0",},
                                         {ySpriteTextInput,SDL_Rect{app.W*950/1503+app.W * 340 / 1365, app.H * 411 / 609, app.W * 50 / 1365, app.H * 28 / 609},"0"},
                                         {sizeSpriteTextInput,SDL_Rect{app.W*950/1503+app.W * 178 / 1365, app.H * 448 / 609, app.W * 65 / 1365, app.H * 28 / 609},"100"},
                                         {directionSpriteTextInput,SDL_Rect{app.W*950/1503+app.W * 326 / 1365, app.H * 448 / 609, app.W * 65 / 1365, app.H * 28 / 609},"90"},
                                         {nameSpriteTextInput,SDL_Rect{app.W*950/1503+app.W * 50 / 1365, app.H * 411 / 609, app.W * 125 / 1365, app.H * 28 / 609},"Sprite1",true,true},
                                         {showButton,SDL_Rect{app.W*950/1503+app.W * 48 / 1365, app.H * 449 / 609, app.W * 36 / 1365, app.H * 33 / 609}},
                                         {hideButton,SDL_Rect{app.W*950/1503+app.W * 48 / 1365+app.W * 36 / 1365, app.H * 449 / 609, app.W * 36 / 1365, app.H * 33 / 609}},
                                 }

            },
            {TAB_CODE,    true, {{Motion,   SDL_Rect{0, app.H * 90 / 609, app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Looks,         SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 1 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Sound,            SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 2 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Events, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 3 / 609, app.W * 60 / 1365,app.H * 45 / 609}},
                                         {Control, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 4 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Sensing, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 5 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Operators, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 6 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Variables, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 7 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {MyBlocks, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 8 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {Pen, SDL_Rect{0, app.H * 90 / 609 + app.H * 45 * 9 / 609,app.W * 60 / 1365, app.H * 45 / 609}},
                                         {WorkSpace, SDL_Rect{app.W*250/1365,app.H*90/559,app.W*853/1365-15*app.W/1365-app.W*250/1365,app.H-app.H*90/559}},
                                         {Extension, SDL_Rect{0, app.H-app.H*38/609,app.W * 60 / 1365, app.H*38/609}},

                                         {move, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 101, 38}},
                                         {turnRDegrees, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*1/610,128,38}},
                                         {turnLDegrees, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*2/610,128,38}},
                                         {goToRandomPosition, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*3/610,146,38}},
                                         {goToMousePointer, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*4/610,146,38}},
                                         {goToXY, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*5/610,125,38}},
                                         {changeXBy, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*6/610,102,38}},
                                         {setXTo, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*7/610,79,38}},
                                         {changeYBy, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*8/610,102,38}},
                                         {setYTo, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*9/610,79,38}},
                                         {moveTextInput, SDL_Rect{app.W * 70 / 1365+37,app.H * 130 / 610+7,28,23},"10"},
                                         {turnRDegreesTextInput, SDL_Rect{app.W * 70 / 1365+51,app.H * 130 / 610+app.H*dis*1/610+6,28,23},"15"},
                                         {turnLDegreesTextInput, SDL_Rect{app.W * 70 / 1365+51,app.H * 130 / 610+app.H*dis*2/610+6,28,23},"15"},
                                         {goToXYTextInput1, SDL_Rect{app.W*70/1365+46,app.H*130/610+app.H*dis*5/610+6,28,23},"0"},
                                         {goToXYTextInput2, SDL_Rect{app.W*70/1365+92,app.H*130/610+app.H*dis*5/610+6,28,23},"0"},
                                         {changeXByTextInput, SDL_Rect{app.W*70/1365+69,app.H*130/610+app.H*dis*6/610+6,28,23},"10"},
                                         {setXToTextInput, SDL_Rect{app.W*70/1365+46,app.H*130/610+app.H*dis*7/610+6,28,23},"0"},
                                         {changeYByTextInput, SDL_Rect{app.W*70/1365+69,app.H*130/610+app.H*dis*8/610+6,28,23},"10"},
                                         {setYToTextInput, SDL_Rect{app.W*70/1365+46,app.H*130/610+app.H*dis*9/610+6,28,23},"0"},

                                         {sayForSeconds, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 161, 38},"",false},
                                         {say, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*diis*1/610, 81, 38},"",false},
                                         {thinkForSeconds, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*diis*2/610,163,38},"",false},
                                         {think, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*diis*3/610, 85, 38},"",false},
                                         {changeSizeBy, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*diis*4/610,116,38},"",false},
                                         {setSizeTo, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*diis*5/610,107,38},"", false},
                                         {show, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*diis*6/610,44,38},"", false},
                                         {hide, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*diis*7/610,44,38},"", false},
                                         {setColorEffect, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*diis*8/610,166,38},"",false},
                                         {setFishEye, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*diis*9/610, 177, 38},"",false},
                                         {setWhirlEffect, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*diis*10/610,165,38},"",false},
                                         {clearGraphicEffect, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*diis*11/610,108,38},"", false},
                                         {sayForSecondsTextInput1, SDL_Rect{app.W * 70 / 1365+32, app.H * 130 / 610+7, 40,23},"Hello!",false,true},
                                         {sayForSecondsTextInput2, SDL_Rect{app.W * 70 / 1365+98, app.H * 130 / 610+6, 28,23},"2",false},
                                         {sayTextInput, SDL_Rect{app.W * 70 / 1365+32, app.H * 130 / 610+app.H*diis*1/610+7, 40, 23},"Hello!",false,true},
                                         {thinkForSecondsTextInput1, SDL_Rect{app.W*70/1365+32,app.H*130/610+app.H*diis*2/610+7, 50,23},"Hmm...",false,true},
                                         {thinkForSecondsTextInput2, SDL_Rect{app.W * 70 / 1365+107, app.H * 130 / 610+app.H*diis*2/610+8, 28,23},"2",false},
                                         {thinkTextInput, SDL_Rect{app.W * 70 / 1365+32, app.H * 130 / 610+app.H*diis*3/610+7, 50, 23},"Hmm...",false,true},
                                         {changeSizeByTextInput, SDL_Rect{app.W*70/1365+83,app.H*130/610+app.H*diis*4/610+6, 28,23},"10",false},
                                         {setSizeToTextInput, SDL_Rect{app.W*70/1365+60,app.H*130/610+app.H*diis*5/610+6, 28,23},"100",false},
                                         {setColorEffectTextInput, SDL_Rect{app.W*70/1365+133,app.H*130/610+app.H*diis*8/610+7,28,23},"0",false},
                                         {setFishEyeTextInput, SDL_Rect{app.W * 70 / 1365+163, app.H * 130 / 610+app.H*diis*9/610+7, 28,23},"0",false},
                                         {setWhirlEffectTextInput, SDL_Rect{app.W*70/1365+136,app.H*130/610+app.H*diis*10/610+7,28,23},"0",false},

                                         {playSoundMeow, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 178, 38},"",false},
                                         {startSoundMeow, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*1/610,127,38},"",false},
                                         {stopAllSounds, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*2/610,83,38},"",false},
                                         {changePitchaEfectBy, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*3/610,182,38},"", false},
                                         {setPitchEffectTo, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*dis*4/610, 165, 38},"",false},
                                         {clearSoundEffects, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*5/610,102,38},"",false},
                                         {changeVolumeBy, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*6/610,131,38},"",false},
                                         {setVolumeTo, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*7/610,123,38},"", false},
                                         {playSoundMeowTextInput, SDL_Rect{app.W * 70 / 1365+63, app.H * 130 / 610+7, 60, 20},"Meow",false,true},
                                         {startSoundMeowTextInput, SDL_Rect{app.W*70/13656+65+61,app.H*130/610+app.H*dis*1/610+7,60,20},"Meow",false,true},
                                         {changePitchaEfectByTextInput2, SDL_Rect{app.W*70/1365+150,app.H*130/610+app.H*dis*3/610+6,28,23},"10", false},
                                         {changePitchaEfectByTextInput1, SDL_Rect{app.W*70/1365+44,app.H*130/610+app.H*dis*3/610+7,52,23},"", false,true},
                                         {setPitchEffectToTextInput2, SDL_Rect{app.W * 70 / 1365+131, app.H * 130 / 610+app.H*dis*4/610+7, 28, 23},"100",false},
                                         {setPitchEffectToTextInput1, SDL_Rect{app.W * 70 / 1365+35, app.H * 130 / 610+app.H*dis*4/610+5, 52, 23},"",false,true},
                                         {changeVolumeByTextInput, SDL_Rect{app.W*70/1365+97,app.H*130/610+app.H*dis*6/610+5,28,23},"-10",false},
                                         {setVolumeToTextInput, SDL_Rect{app.W*70/1365+75,app.H*130/610+app.H*dis*7/610+5,28,23},"100", false},

                                         {whenGreenFlagClicked, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 97, 49},"",false},
                                         {whenSpaceKeyPressed, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*dis*1/610, 163, 49},"",false},
                                         {whenThisSpriteClicked, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*dis*2/610, 122, 49},"",false},
                                         {whenIReceiveMassege1, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*dis*3/610, 165, 49},"",false},
                                         {broadcast, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*dis*4/610, 142, 38},"",false},
                                         {broadcastAndWait, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610+app.H*dis*5/610, 188, 38},"",false},

                                         {waitSecondes, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 111, 38},"",false},
                                         {repeat, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*1/610,108,76},"",false},
                                         {forever, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*8/(610*3),108,76},"",false},
                                         {waitSecondesTextInput, SDL_Rect{app.W * 70 / 1365+31, app.H * 130 / 610+6, 28, 23},"1",false},
                                         {repeatTextInput, SDL_Rect{app.W*70/1365+42,app.H*130/610+app.H*dis*1/610+7,28,23},"10",false},

                                         {askAndWait, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 191, 38},"",false},
                                         {askAndWaitTextInput, SDL_Rect{app.W * 70 / 1365+33, app.H * 130 / 610+6, 108, 23},"What's your name?",false,true},

                                         {eraseAll, SDL_Rect{app.W * 70 / 1365, app.H * 130 / 610, 91, 44},"",false},
                                         {stamp, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*1/610,79,44},"",false},
                                         {penDown, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*2/610,97,44},"",false},
                                         {penUp, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*3/610,83,44},"",false},
                                         {setPenColorTo, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*4/610,146,44},"",false},
                                         {setPenBrightnees, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*5/610,216,44},"",false},
                                         {setPenSaturation, SDL_Rect{app.W*70/1365,app.H*130/610+app.H*dis*6/610,213,44},"",false},
                                         {setPenBrightneesTextInput, SDL_Rect{app.W*70/1365+183,app.H*130/610+app.H*dis*5/610+9,28,23},"50",false},
                                         {setPenSaturationTextInput, SDL_Rect{app.W*70/1365+181,app.H*130/610+app.H*dis*6/610+9,28,23},"50",false},
                                         {setPenColorToColorInput, SDL_Rect{app.W*70/1365+127,app.H*130/610+app.H*dis*4/610+10,23,17},"",false},
                                 }
            },
            {TAB_COSTUMES,false ,  {{nameCostume,SDL_Rect{app.W * 215 / 1365, app.H * 113 / 609, app.W * 125 / 1365, app.H * 28 / 609}},
                                         {uploadImage,SDL_Rect{app.W * 215 / 1365, app.H * 163 / 609, app.W * 125 / 1365, app.H * 28 / 609}},
                                         {xImage,SDL_Rect{app.W * 370 / 1365, app.H * 163 / 609, app.W * 50 / 1365, app.H * 28 / 609}},
                                         {yImage,SDL_Rect{app.W * 455 / 1365, app.H * 163 / 609, app.W * 50 / 1365, app.H * 28 / 609}},
                                         {sizeImage,SDL_Rect{app.W * 540 / 1365, app.H * 163 / 609, app.W * 65 / 1365, app.H * 28 / 609}},
                                         {nameCostumeTextInput,SDL_Rect{app.W * 215 / 1365, app.H * 113 / 609, app.W * 125 / 1365, app.H * 28 / 609},"costume1", true, true},
                                         {xImageTextInput,SDL_Rect{app.W * 370 / 1365, app.H * 163 / 609, app.W * 50 / 1365, app.H * 28 / 609},"0"},
                                         {yImageTextInput,SDL_Rect{app.W * 455 / 1365, app.H * 163 / 609, app.W * 50 / 1365, app.H * 28 / 609},"0"},
                                         {sizeImageTextInput,SDL_Rect{app.W * 540 / 1365, app.H * 163 / 609, app.W * 65 / 1365, app.H * 28 / 609},"100"},
                                         {mouseButton,SDL_Rect{app.W * 170 / 1365, app.H * 240 / 609, 43, 43}},
                                         {eraser,SDL_Rect{app.W * 240 / 1365, app.H * 240 / 609, 43, 43}},
                                         {brush,SDL_Rect{app.W * 170 / 1365, app.H * 290 / 609, 43, 43}},
                                         {textOut,SDL_Rect{app.W * 240 / 1365, app.H * 290 / 609, 43, 43}},
                                         {rectangle,SDL_Rect{app.W * 170 / 1365, app.H * 340 / 609, 43, 43}},
                                         {circle,SDL_Rect{app.W * 240 / 1365, app.H * 340 / 609, 43, 43}},
                                         {lineS,SDL_Rect{app.W * 170 / 1365, app.H * 390 / 609, 43, 43}},
                                         {fill,SDL_Rect{app.W * 240 / 1365, app.H * 390 / 609, 43, 43}},
                                         {showSpace,SDL_Rect{app.W * 297 / 1365, app.H * 240 / 609, app.W * 538 / 1365, app.H * 350 / 610}},
                                         {flipHorizontal,SDL_Rect{app.W * 355 / 1365, app.H * 105 / 609, app.W * 80 / 1365, app.H * 50 / 609}},
                                         {flipVertical,SDL_Rect{app.W * 435 / 1365, app.H * 105 / 609, app.W * 80 / 1365, app.H * 50 / 609}},
                                         {deleteButton,SDL_Rect{app.W * 515 / 1365, app.H * 105 / 609, app.W * 80 / 1365, app.H * 50 / 609}},
                                         {colorChose,SDL_Rect{app.W * 175 / 1365, app.H * 440 / 609, 35, 36}},
                                         {costumeEditor,SDL_Rect{app.W * 28 / 1350, app.H * 100 / 609, app.W * 84 / 1350, app.H * 70 / 609}},
                                         {backgroundEditor,SDL_Rect{app.W * 28 / 1350, app.H * 200 / 609, app.W * 84 / 1350, app.H * 70 / 609}},
                                         {backgroundName,SDL_Rect{app.W * 215 / 1365, app.H * 113 / 609, app.W * 125 / 1365, app.H * 28 / 609},"background",true,true},
                                         {saveLibrary,SDL_Rect{app.W * 700 / 1365, app.H * 163 / 609, app.W * 120 / 1365, app.H * 28 / 609}},
                                         {save,SDL_Rect{app.W * 750 / 1365, app.H * 113 / 609, app.W * 70 / 1365, app.H * 28 / 609}},

                                 }
            },
            {TAB_EXTENSION,false,{{BackExtension,SDL_Rect{0,0,app.W * 130 / 1365, app.H * 50 / 609}},
                                         {PenExtension,SDL_Rect{app.W * 20 / 1365, app.H * 70 / 609, 297, app.H * 245 / 609}},
                                         {CLOSE_BUTTONExtension, SDL_Rect{app.W-app.W/30,0,app.W/30,app.H/25}},
                                         {WINDOW_BUTTONExtension, SDL_Rect{app.W-app.W*2/30,0,app.W/30,app.H/25}},
                                         {MINIMIZED_BUTTONExtension, SDL_Rect{app.W-app.W*3/30,0,app.W/30,app.H/25}}
                                    }

            },
            {TAB_GALLERY, false, {{BackGallery, SDL_Rect{0, 0, app.W * 130 / 1365, app.H * 50 / 609}},
                                         {CLOSE_BUTTONGallery, SDL_Rect{app.W-app.W/30,0,app.W/30,app.H/25}},
                                         {WINDOW_BUTTONGallery, SDL_Rect{app.W-app.W*2/30,0,app.W/30,app.H/25}},
                                         {MINIMIZED_BUTTONGallery, SDL_Rect{app.W-app.W*3/30,0,app.W/30,app.H/25}},
                                         {uploadBackground,SDL_Rect{libW*0+an*1,  libY ,  libW, libH}},
                                         {library1 ,  SDL_Rect{libW*1  + an*2 ,  libY ,  libW, libH}},
                                         {library2 ,  SDL_Rect{libW*2  + an*3 ,  libY ,  libW, libH}},
                                         {library3 ,  SDL_Rect{libW*3  + an*4 ,  libY ,  libW, libH}},
                                         {library4 ,  SDL_Rect{libW*4  + an*5 ,  libY ,  libW, libH}},
                                         {library5 ,  SDL_Rect{libW*5  + an*6 ,  libY ,  libW, libH}},
                                         {library6 ,  SDL_Rect{libW*6  + an*7 ,  libY ,  libW, libH}},
                                         {library7 ,  SDL_Rect{libW*7  + an*8 ,  libY,  libW, libH}},
                                         {library8 ,  SDL_Rect{libW*0  + an*1 ,  libY+libH*1+anY*1 ,  libW, libH}},
                                         {library9 ,  SDL_Rect{libW*1  + an*2 ,  libY+libH*1+anY*1,  libW, libH}},
                                         {library10 ,  SDL_Rect{libW*2  + an*3 ,  libY+libH*1+anY*1 ,  libW, libH}},
                                         {library11 ,  SDL_Rect{libW*3  + an*4 ,  libY+libH*1+anY*1 ,  libW, libH}},
                                         {library12 ,  SDL_Rect{libW*4  + an*5 ,  libY+libH*1+anY*1 ,  libW, libH}},
                                         {library13 ,  SDL_Rect{libW*5  + an*6 ,  libY+libH*1+anY*1 ,  libW, libH}},
                                         {library14 ,  SDL_Rect{libW*6  + an*7 ,  libY+libH*1+anY*1 ,  libW, libH}},
                                         {library15 ,  SDL_Rect{libW*7  + an*8 ,  libY+libH*1+anY*1 ,  libW, libH}},
                                         {library16 ,  SDL_Rect{libW*0  + an*1 ,  libY+libH*2+anY*2 ,  libW, libH}},
                                         {library17 ,  SDL_Rect{libW*1  + an*2 ,  libY+libH*2+anY*2,  libW, libH}},
                                         {library18 ,  SDL_Rect{libW*2  + an*3 ,  libY+libH*2+anY*2 ,  libW, libH}},
                                         {library19 ,  SDL_Rect{libW*3  + an*4 ,  libY+libH*2+anY*2 ,  libW, libH}},
                                         {library20 ,  SDL_Rect{libW*4  + an*5 ,  libY+libH*2+anY*2 ,  libW, libH}},
                                         {library21 ,  SDL_Rect{libW*5  + an*6 ,  libY+libH*2+anY*2 ,  libW, libH}},
                                         {library22 ,  SDL_Rect{libW*6  + an*7 ,  libY+libH*2+anY*2 ,  libW, libH}},
                                         {library23 ,  SDL_Rect{libW*7  + an*8 ,  libY+libH*2+anY*2 ,  libW, libH}},

                                 }

            }

    };


    app.paint[mouseButton]=true;
    app.paint[eraser]=false;
    app.paint[brush]=false;
    app.paint[textOut]=false;
    app.paint[rectangle]=false;
    app.paint[circle]=false;
    app.paint[lineS]=false;
    app.paint[fill]=false;

   // app.stageRect={app.W*950/1503,app.H*90/609,app.W*549/1503,app.H*276/609};
    app.stageRect={app.W*950/1503,app.H*90/609,app.W*543/1503,app.H*300/609};

    Stage stage;
    //Sprite gorba{gorbaFront,0, 0,100,100, LoadTexture(app.renderer,"icons/gorba(1).png"),90,0,0};
    //app.box.t=LoadTexture(app.renderer,"icons/gorba(1).png");
    SDL_Surface* surf = IMG_Load("icons/gorba(1).png");
    app.boxOriginalSurface = surf;
    app.box.t = SDL_CreateTextureFromSurface(app.renderer, surf);
    app.saytexture= LoadTexture(app.renderer,"icons/saying.png");
    app.thinktexture= LoadTexture(app.renderer,"icons/thinking.png");
    app.penTexture= SDL_CreateTexture(app.renderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,app.stageRect.w,app.stageRect.h);
    SDL_SetTextureBlendMode(app.penTexture,SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(app.renderer,app.penTexture);
    SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);
    SDL_RenderClear(app.renderer);
    SDL_SetRenderTarget(app.renderer, nullptr);




    //  app.box.t=LoadTexture(app.renderer,"icons/gorba(1).png");


    for(auto &it1:tabButtons)
    {
        if(it1.ID==TAB_COSTUMES)
        {
            for(auto &it2:it1.buttons)
                if(it2.ID==showSpace)
                {
                    app.paintSpace=it2.rect;
                    app.textureHelperCos= SDL_CreateTexture(app.renderer,
                                                            SDL_PIXELFORMAT_RGBA8888,
                                                            SDL_TEXTUREACCESS_TARGET,
                                                            it2.rect.w,
                                                            it2.rect.h);
                    SDL_SetTextureBlendMode(app.textureHelperCos, SDL_BLENDMODE_BLEND);
                    app.box.t=SDL_CreateTexture(
                            app.renderer,
                            SDL_PIXELFORMAT_RGBA8888,
                            SDL_TEXTUREACCESS_TARGET,
                            it2.rect.w,
                            it2.rect.h
                    );
                    app.box.background=SDL_CreateTexture(
                            app.renderer,
                            SDL_PIXELFORMAT_RGBA8888,
                            SDL_TEXTUREACCESS_TARGET,
                            it2.rect.w,
                            it2.rect.h
                    );
                    SDL_SetTextureBlendMode(app.box.background, SDL_BLENDMODE_BLEND);
                    SDL_SetTextureBlendMode(app.box.t, SDL_BLENDMODE_BLEND);
                    SDL_SetRenderTarget(app.renderer,app.box.t);
                    SDL_SetRenderDrawColor(app.renderer,0,0,0,0);
                    SDL_RenderClear(app.renderer);
                    image(app,it2.rect.w/2,it2.rect.h/2, 1, gorbaStandard, true);
                    SDL_SetRenderTarget(app.renderer,NULL);
                    break;
                }
        }
    }

    app.box.backgroundStage=SDL_CreateTexture(
            app.renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            app.stageRect.w,
            app.stageRect.h
    );
    SDL_SetTextureBlendMode(app.box.backgroundStage, SDL_BLENDMODE_BLEND);



    app.hChange = FindFirstChangeNotificationA(
            "backgroundLibrary",
            FALSE,
            FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_SIZE | FILE_NOTIFY_CHANGE_LAST_WRITE
    );

    loadPNGLibrary(app);

    Theme light, color;
    color = light; // default color

    float scale=std::min(app.W/1365.0,app.H/610.0);

    app.font["Roman9"] = TTF_OpenFont("fonts/HelveticaNeue-Roman.otf", std::round(9*scale));
    app.font["Roman10"] = TTF_OpenFont("fonts/HelveticaNeue-Roman.otf", std::round(10*scale));
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
    app.font["Roman15"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(15*scale));
    app.font["Roman16"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(16*scale));
    app.font["Roman17"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(17*scale));
    app.font["Roman18"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(18*scale));
    app.font["Roman19"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(19*scale));
    app.font["Roman20"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(20*scale));
    app.font["Roman21"]=TTF_OpenFont("fonts/HelveticaNeue-Roman.otf",std::round(21*scale));
    app.font["Bold10"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(12*scale));
    app.font["Bold12"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(12*scale));
    app.font["Bold13"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(13*scale));
    app.font["Bold14"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(14*scale));
    app.font["Bold16"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(16*scale));
    app.font["Bold19"]=TTF_OpenFont("fonts/HelveticaNeue-Bold.otf",std::round(19*scale));
    app.font["Medium9"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(9*scale));
    app.font["Medium10"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(10*scale));
    app.font["Medium11"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(11*scale));
    app.font["Medium12"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(12*scale));
    app.font["Medium14"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(14*scale));
    app.font["Medium16"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(16*scale));
    app.font["Medium17"]=TTF_OpenFont("fonts/HelveticaNeue-Medium.otf",std::round(16*scale));
    app.font["Thin14"]=TTF_OpenFont("fonts/HelveticaNeue-Thin.otf",std::round(14*scale));


    //
    app.cursorArrow = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
    app.cursorIBeam = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
    app.cursorHand  = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);

    TabTexture texture;
    SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
    //==========================
    int w;
    int h;
    SDL_QueryTexture(app.box.t,NULL,NULL,&w,&h);
    app.box.w=w/2;
    app.box.h=h/2;
    app.boxh=app.box.h;
    app.boxw=app.box.w;





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
        AllTabButtonActions(tabButtons,app,color,texture,mouse,keyboardButton,buttonTextures);
        Engine(app,tabButtons,mouse,keyboardButton);
        PrintLog(app);
        UpdateSpriteState(tabButtons,app);
        SetCursor(app);
        SDL_RenderPresent(renderer);
        SDL_Delay(5);
    }



    SDL_DestroyTexture(tabTexture.general);
    DestroyButtonTexture(buttonTextures);



    SDL_FreeCursor(app.cursorArrow);
    SDL_FreeCursor(app.cursorIBeam);
    SDL_FreeCursor(app.cursorHand);
    FindCloseChangeNotification(app.hChange);
    for (auto &it:app.library)
    {
        SDL_DestroyTexture(it.second);
    }
    app.library.clear();
    app.libraryName.clear();
    SDL_DestroyTexture(app.box.t);
    SDL_DestroyTexture(app.box.background);
    SDL_DestroyTexture(app.box.backgroundStage);
    SDL_DestroyTexture(app.textureHelperImage);
    SDL_DestroyTexture(app.textureHelperText);
    SDL_DestroyTexture(app.textureHelperCos);
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
void AllTabButtonActions(std::vector<AllTabButtons> &tab,AppState &app,Theme &color,TabTexture &texture,MouseState &mouse,KeyboardButton &key,ButtonTextures buttonTextures)
{
    for(auto &it:tab)
        if(it.active)
        {
            switch (it.ID) {
                case TAB_GENERAL:
                    RenderTextureGeneral(tab[0].buttons,app,color.general,texture,buttonTextures,tab,mouse,key);
                    SDL_RenderCopy(app.renderer,texture.general, nullptr, nullptr);
                    if(app.box.isShowing)
                        RenderStage(app,app.box);
                    break;
                case TAB_CODE:
                    RenderCodeTap(it.buttons,app,color.code,texture,mouse,tab);
                    break;
                case TAB_COSTUMES:
                    RenderCostumesTap(it.buttons,app,color.code,texture,mouse,tab);
                    break;
                case TAB_EXTENSION:
                    RenderExtensionTab(tab,it.buttons,app,color.code,texture);
                    break;
                case TAB_GALLERY:
                    RenderGalleryTab(tab,it.buttons,app,color.code,texture);
                    break;


            }

        }

    for(auto &it:tab)
        if(it.active)
        {
            if(it.ID==TAB_GENERAL)
            {
                RenderGeneralTap(it.buttons,app,color.general,mouse,tab);
            }
        }

}
void RenderCodeTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeCodeTab &color,TabTexture &texture,MouseState &mouse,std::vector<AllTabButtons> &tab)
{
    for(auto &it:buttons)
    {
        if (  ((0 <= it.ID && it.ID <= 8) || (it.ID==Pen && app.activeExtention) )&& it.leftClick && !app.fileMenu)
        {
            memset(app.activeCodePage, 0, sizeof(app.activeCodePage));
            app.activeCodePage[it.ID] = true;
            for (auto &it2: buttons) {
                if (it.ID * 30 + 200 <= it2.ID && it2.ID < it.ID * 30 + 200 + 30)
                    it2.active = true;
                else if (200 <= it2.ID && it2.ID <= 500)
                    it2.active = false;
                if (it.ID * 30 + 1000 <= it2.ID && it2.ID < it.ID * 30 + 1000 + 30)
                    it2.active = true;
                else if (1000 <= it2.ID && it2.ID <= 1500)
                    it2.active = false;
            }
            RenderTextureCodeTab(buttons, app, color, texture);
            break;
        }
        if (it.ID == Pen && it.leftClick && !app.fileMenu && app.activeExtention)
        {
            memset(app.activeCodePage, 0, sizeof(app.activeCodePage));
            app.activeCodePage[9] = true;
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
            if(it.ID==1060 || it.ID==1062)
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,it.text,"Roman11",SDL_Color{255, 255, 255,255});
            else
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,it.text,"Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==setPenColorTo && app.activeCodePage[9])
        {
            filledEllipseRGBA(app.renderer,it.rect.x+138,it.rect.y+18,12+1,11,app.penColor.r,app.penColor.g,app.penColor.b,app.penColor.a);
            aaellipseRGBA(app.renderer,it.rect.x+138,it.rect.y+18,12+1,11,168,189,203,255);
        }
        if(it.ID==setPenColorToColorInput && app.activeCodePage[9])
        {
            if(it.leftClick)
            {
                unsigned char defaultRGB[3] = {
                        app.colorPaint.r,
                        app.colorPaint.g,
                        app.colorPaint.b
                };
                unsigned char resultRGB[3] = { 0, 0, 0 };

                const char* result = tinyfd_colorChooser(
                        "Choose Color",
                        NULL,
                        defaultRGB,
                        resultRGB
                );

                if (result != NULL)
                {
                    app.penColor.r = resultRGB[0];
                    app. penColor.g = resultRGB[1];
                    app.penColor.b = resultRGB[2];
                    app.penColor.a = 255;
                }
            }
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
            else if(it.ID==Pen)
            {
                if(it.onButton)
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Pen","Roman10.4",color.leftPanelTextMouse);
                else
                    text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Pen","Roman10.4",color.leftPanelText);
            }
        }
        if(it.ID==Pen && app.activeExtention)
        {
            if(it.onButton)
                text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Pen","Roman10.4",color.leftPanelTextMouse);
            else
                text(app,it.rect.w/2,it.rect.y+app.H*35/609,"Pen","Roman10.4",color.leftPanelText);
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
                if(it.ID==322)
                    app.blockHelper.type=loop;
                if(it.ID==324)
                    app.blockHelper.type=loopInfinity;
                if(290<=it.ID && it.ID<=296)
                    app.blockHelper.type=start;
                app.blockHelper.index=app.block.size();
                app.blockHelper.rect.w=it.rect.w;
                app.blockHelper.rect.h=it.rect.h;
                app.blockHelper.color=app.penColor;

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
                    if(blockDistanceTest(mouse,app.blockHelper,app.block)==1 && (app.blockHelper.type==loop || app.blockHelper.type==normal || app.blockHelper.type==loopInfinity))
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
                        if(app.block[app.block.size()-1].type!=loopInfinity)
                            app.block.push_back(app.blockHelper);
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
                        }
                        //   app.allblock.push_back(app.blockHelper);
                    }
                    else if(blockDistanceTest(mouse,app.blockHelper,app.block)==2 && (app.block[app.block.size()-1].type==loop || app.block[app.block.size()-1].type==loopInfinity) && app.blockHelper.type==normal)
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
                            app.childHelper.index=0;
                            app.childHelper.color=app.penColor;

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
                            app.childHelper.index=app.block[app.block.size()-1].child.size();
                            app.childHelper.color=app.penColor;

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
        if(it.ID==Extension)
        {
            if(it.leftClick)
            {
                SDL_RenderClear(app.renderer);
                for(auto &it2:tab)
                {
                    it2.active=false;
                    if(it2.ID==TAB_EXTENSION)
                        it2.active=true;

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

    SDL_Rect leftPanel={0,y,w,app.H-y};
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
        if(it.ID==Pen && app.activeExtention)
        {
            if(app.activeCodePage[it.ID])
            {
                int texty=app.H*106/609;
                std::string textfont="Bold14";
                text(app,app.W*70/1365,texty,"Pen",textfont,SDL_Color{87,94,117,255},true);
            }
            image(app,it.rect.w/2,it.rect.y+app.H*17/609,1,it.ID,true);
        }
        if(200 <= it.ID && it.ID <= 500)
        {
            if(it.active)
                image(app,it.rect.x,it.rect.y,1,it.ID);
        }
        if(it.ID==Extension)
        {
            SDL_SetRenderDrawColor(app.renderer,133,92,214,255);
            SDL_RenderFillRect(app.renderer,&it.rect);
            image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1,it.ID,true);
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
void image(AppState &app,int x,int y,double scale,int id,bool xyMiddle,int readX,int readY,double readWScale,double readHScale,bool getTexture,SDL_Texture* t)
{
    if(!getTexture)
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
   else
    {
        int imageW,imageH;
        SDL_QueryTexture(t,NULL,NULL,&imageW,&imageH);
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

        SDL_RenderCopy(app.renderer,t,&scr,&rect);
    }

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
void CheckIsTyping(AppState &app,std:: vector<AllTabButtons> &tab,MouseState &mouse) {
    app.isOnTextInput = false;
    for (auto it1: tab)
        if (it1.active)
            for(auto it2:it1.buttons)
            {
                if(((1000<=it2.ID && it2.ID<=1500) || (3500<=it2.ID && it2.ID<=3503) || ((4041<=it2.ID && it2.ID<=4045) && !app.engineRunning) || it2.ID==5000) && it2.active)
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
void DrawBlock(AppState &app,Block  &block)
{
    if(!block.isrunning)
    {
        if((block.type==loop||block.type==loopInfinity) && block.child.size()!=0)
        {
            image(app,block.rect.x,block.rect.y,1,block.ID,false,0,0,1,39.0/76.0);
            for(int i=0;i<block.child.size();i++)
            {
                image(app,block.rect.x,block.rect.y+36+i*30,1,repeatHelper);
            }
            image(app,block.rect.x,block.rect.y+35+(block.child.size())*30,1,block.ID,false,0,47,1,1);

            for(auto &it:block.child)
            {
                app.drawBlockHelper.ID=it.ID;
                app.drawBlockHelper.rect=it.rect;
                app.drawBlockHelper.rectText1=it.rectText1;
                app.drawBlockHelper.rectText2=it.rectText2;
                app.drawBlockHelper.p1=it.p1;
                app.drawBlockHelper.p2=it.p2;
                app.drawBlockHelper.type=it.type;
                app.drawBlockHelper.color=it.color;
                app.blockHelper.isrunning=it.isrunning;
                DrawBlock(app,app.drawBlockHelper);
            }
        }
        else
        {
            image(app,block.rect.x,block.rect.y,1,block.ID);
        }
    }
    else
    {
        SDL_Texture* b=createRedTintedTexture(app.renderer,app.texture[block.ID]);
        if((block.type==loop||block.type==loopInfinity) && block.child.size()!=0)
        {
            image(app,block.rect.x,block.rect.y,1,block.ID,false,0,0,1,39.0/76.0,true,b);
            for(int i=0;i<block.child.size();i++)
            {
                image(app,block.rect.x,block.rect.y+36+i*30,1,repeatHelper,false,0,0,1,1,true,b );
            }
            image(app,block.rect.x,block.rect.y+35+(block.child.size())*30,1,block.ID,false,0,47,1,1,true,b);

            for(auto &it:block.child)
            {
                app.drawBlockHelper.ID=it.ID;
                app.drawBlockHelper.rect=it.rect;
                app.drawBlockHelper.rectText1=it.rectText1;
                app.drawBlockHelper.rectText2=it.rectText2;
                app.drawBlockHelper.p1=it.p1;
                app.drawBlockHelper.p2=it.p2;
                app.drawBlockHelper.type=it.type;
                app.drawBlockHelper.color=it.color;
                app.blockHelper.isrunning=it.isrunning;
                DrawBlock(app,app.drawBlockHelper);
            }
        }
        else
        {
            image(app,block.rect.x,block.rect.y,1,block.ID,false,0,0,1,1,true,b);
        }
        SDL_DestroyTexture(b);
    }


    if(block.ID==setPenColorTo)
    {
        filledEllipseRGBA(app.renderer,block.rect.x+138,block.rect.y+18,12+1,11,block.color.r,block.color.g,block.color.b,block.color.a);
        aaellipseRGBA(app.renderer,block.rect.x+138,block.rect.y+18,12+1,11,168,189,203,255);
    }
    if(block.rectText1.w != 0)
    {
        if(block.ID==260 || block.ID==262)
            text(app,block.rectText1.x+block.rectText1.w/2,block.rectText1.y+block.rectText1.h/2,block.p1,"Roman11",SDL_Color{255, 255, 255,255});
        else
            text(app,block.rectText1.x+block.rectText1.w/2,block.rectText1.y+block.rectText1.h/2,block.p1,"Roman11",SDL_Color{87, 94, 117,255});
    }
    if(block.rectText2.w != 0)
    {
        text(app,block.rectText2.x+block.rectText2.w/2,block.rectText2.y+block.rectText2.h/2,block.p2,"Roman11",SDL_Color{87, 94, 117,255});
    }

}
void LoadMyTexture(AppState &app)
{
    app.texture[move]=LoadTexture(app.renderer,"blocks/move.png");
    app.texture[turnRDegrees]=LoadTexture(app.renderer,"blocks/turnRDegrees.png");
    app.texture[turnLDegrees]=LoadTexture(app.renderer,"blocks/turnLDegrees.png");
    app.texture[goToRandomPosition]=LoadTexture(app.renderer,"blocks/goToRandomPosition.png");
    app.texture[goToMousePointer]=LoadTexture(app.renderer,"blocks/goToMousePointer.png");
    app.texture[goToXY]=LoadTexture(app.renderer,"blocks/goToXY.png");
    app.texture[changeXBy]=LoadTexture(app.renderer,"blocks/changeXBy.png");
    app.texture[setXTo]=LoadTexture(app.renderer,"blocks/setXTo.png");
    app.texture[changeYBy]=LoadTexture(app.renderer,"blocks/changeYBy.png");
    app.texture[setYTo]=LoadTexture(app.renderer,"blocks/setYTo.png");

    app.texture[sayForSeconds]=LoadTexture(app.renderer,"blocks/sayForSeconds.png");
    app.texture[say]=LoadTexture(app.renderer,"blocks/say.png");
    app.texture[thinkForSeconds]=LoadTexture(app.renderer,"blocks/thinkForSeconds.png");
    app.texture[think]=LoadTexture(app.renderer,"blocks/think.png");
    app.texture[setSizeTo]=LoadTexture(app.renderer,"blocks/setSizeTo.png");
    app.texture[changeSizeBy]=LoadTexture(app.renderer,"blocks/changeSizeBy.png");
    app.texture[show]=LoadTexture(app.renderer,"blocks/show.png");
    app.texture[hide]=LoadTexture(app.renderer,"blocks/hide.png");
    app.texture[setColorEffect]=LoadTexture(app.renderer,"blocks/setColorEffect.png");
    app.texture[setFishEye]=LoadTexture(app.renderer,"blocks/SetBrightnessEffectBy.png");
    app.texture[setWhirlEffect]=LoadTexture(app.renderer,"blocks/setGhostEffectBy.png");
    app.texture[clearGraphicEffect]=LoadTexture(app.renderer,"blocks/clearGraphicEffect.png");

    app.texture[playSoundMeow]=LoadTexture(app.renderer,"blocks/slaySound.png");
    app.texture[startSoundMeow]=LoadTexture(app.renderer,"blocks/startSound.png");
    app.texture[stopAllSounds]=LoadTexture(app.renderer,"blocks/stopAllSounds.png");
    app.texture[changePitchaEfectBy]=LoadTexture(app.renderer,"blocks/changePitchaEfectBy.png");
    app.texture[setPitchEffectTo]=LoadTexture(app.renderer,"blocks/setPitchEffectTo.png");
    app.texture[clearSoundEffects]=LoadTexture(app.renderer,"blocks/clearSoundEffects.png");
    app.texture[changeVolumeBy]=LoadTexture(app.renderer,"blocks/changeVolumeBy.png");
    app.texture[setVolumeTo]=LoadTexture(app.renderer,"blocks/setVolumeTo.png");

    app.texture[whenGreenFlagClicked]=LoadTexture(app.renderer,"blocks/whenGreenFlagClicked.png");
    app.texture[whenSpaceKeyPressed]=LoadTexture(app.renderer,"blocks/whenSpaceKeyPressed.png");
    app.texture[whenThisSpriteClicked]=LoadTexture(app.renderer,"blocks/whenThisSpriteClicked.png");
    app.texture[whenIReceiveMassege1]=LoadTexture(app.renderer,"blocks/whenIReceiveMassege1.png");
    app.texture[broadcast]=LoadTexture(app.renderer,"blocks/broadcast.png");
    app.texture[broadcastAndWait]=LoadTexture(app.renderer,"blocks/broadcastAndWait.png");

    app.texture[waitSecondes]=LoadTexture(app.renderer,"blocks/waitSecondes.png");
    app.texture[repeat]=LoadTexture(app.renderer,"blocks/repeat.png");
    app.texture[repeatHelper]=LoadTexture(app.renderer,"blocks/repeatHelper.png");
    app.texture[forever]=LoadTexture(app.renderer,"blocks/forever .png");


    app.texture[askAndWait]=LoadTexture(app.renderer,"blocks/askAndWait.png");

    app.texture[eraseAll]=LoadTexture(app.renderer,"blocks/eraseAll.png");
    app.texture[stamp]=LoadTexture(app.renderer,"blocks/stamp.png");
    app.texture[penDown]=LoadTexture(app.renderer,"blocks/penDown.png");
    app.texture[penUp]=LoadTexture(app.renderer,"blocks/penUp.png");
    app.texture[setPenColorTo]=LoadTexture(app.renderer,"blocks/setPenColorTo.png");
    app.texture[setPenBrightnees]=LoadTexture(app.renderer,"blocks/setPenBrightnees.png");
    app.texture[setPenSaturation]=LoadTexture(app.renderer,"blocks/setPenSaturation.png");

    app.texture[mouseButton]=LoadTexture(app.renderer,"icons/mouse.png");
    app.texture[eraser]=LoadTexture(app.renderer,"icons/eraser.png");
    app.texture[brush]=LoadTexture(app.renderer,"icons/brushButton.png");
    app.texture[lineS]=LoadTexture(app.renderer,"icons/lineS.png");
    app.texture[rectangle]=LoadTexture(app.renderer,"icons/rectangle.png");
    app.texture[textOut]=LoadTexture(app.renderer,"icons/textOut.png");
    app.texture[circle]=LoadTexture(app.renderer,"icons/circle.png");
    app.texture[fill]=LoadTexture(app.renderer,"icons/fill.png");
    app.texture[mouseButtonWhite]=LoadTexture(app.renderer,"icons/mouseWhite.png");
    app.texture[eraserWhite]=LoadTexture(app.renderer,"icons/eraserWhite.png");
    app.texture[brushWhite]=LoadTexture(app.renderer,"icons/brushButtonWhite.png");
    app.texture[lineSWhite]=LoadTexture(app.renderer,"icons/lineSWhite.png");
    app.texture[rectangleWhite]=LoadTexture(app.renderer,"icons/rectangleWhite.png");
    app.texture[textOutWhite]=LoadTexture(app.renderer,"icons/textOutWhite.png");
    app.texture[circleWhite]=LoadTexture(app.renderer,"icons/circleWhite.png");
    app.texture[fillWhite]=LoadTexture(app.renderer,"icons/fillWhite.png");
    app.texture[gorbaStandard]=LoadTexture(app.renderer, "icons/gorbaStandard.png");
    app.texture[flipHorizontal]=LoadTexture(app.renderer, "icons/flipHorizontal.png");
    app.texture[flipVertical]=LoadTexture(app.renderer, "icons/flipVertical.png");
    app.texture[deleteButton]=LoadTexture(app.renderer, "icons/delete.png");
    app.texture[Extension]=LoadTexture(app.renderer, "icons/extension.png");
    app.texture[Pen]=LoadTexture(app.renderer, "icons/pen.png");
    app.texture[PenPhoto]=LoadTexture(app.renderer, "icons/penPhoto.png");
    app.texture[PenExtension]=LoadTexture(app.renderer, "icons/penExtemsion.png");
    app.texture[showButton]=LoadTexture(app.renderer, "icons/show.png");
    app.texture[showButtonActive]=LoadTexture(app.renderer, "icons/showActive.png");
    app.texture[hideButton]=LoadTexture(app.renderer, "icons/hide.png");
    app.texture[hideButtonActive]=LoadTexture(app.renderer, "icons/hideActive.png");
    app.texture[backgroundGallery]=LoadTexture(app.renderer, "icons/backgroundGallery.png");
    app.texture[uploadBackground]=LoadTexture(app.renderer, "icons/uploadLogo.png");

}
void RenderCostumesTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeCodeTab &color,TabTexture &texture,MouseState &mouse,std::vector<AllTabButtons> &tabs)
{
    int y=app.H * 90 / 609;
    int w=app.W * 137/1365;
    roundedBoxRGBA(app.renderer,0,y,app.W*853/1365,app.H,15*app.W/1365,255,255,255,255);

    SDL_Rect leftPanel={0,y,w,app.H-y};
    SDL_SetRenderDrawColor(app.renderer,217,227,242,255);
    SDL_RenderFillRect(app.renderer,&leftPanel);

    roundedRectangleRGBA(app.renderer,-20,y,app.W*853/1365,app.H,15,color.line.r,color.line.g,color.line.b,color.line.a);
    aalineRGBA(app.renderer,w,y,w,app.H,color.line.r,color.line.g,color.line.b,color.line.a);

    SDL_SetRenderDrawColor(app.renderer, 217, 217, 217, 255);
    for (int x =app.W*160/1365 ; x <app.W*840/1365; x += 5)
    {
        int endX =x+2;
        if (endX > app.W*842/1365)
            endX = app.W*842/1365;
        SDL_RenderDrawLine(app.renderer, x, app.H*215/609, endX,  app.H*215/609);
    }

    for(auto &it:buttons)
    {
        if(it.ID==showSpace)
        {
            app.xPaint=it.rect.x;
            app.yPaint=it.rect.y;
            int size=11;
            for(int i=0;i<(it.rect.w+size)/size;i++)
                for(int j=0;j<(it.rect.h+size)/size;j++)
                {
                    SDL_Rect moraba={it.rect.x+i*size,it.rect.y+j*size,size,size};
                    if(i*size+size>it.rect.w)
                        moraba.w=it.rect.w-i*size;
                    if(j*size+size>it.rect.h)
                        moraba.h=it.rect.h-j*size;

                    if((i+j)%2==1)
                    {
                        SDL_SetRenderDrawColor(app.renderer,234,240,248,255);
                        SDL_RenderFillRect(app.renderer,&moraba);
                    }

                }
            textureRenderer(app,tabs,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1);
            SDL_SetRenderDrawColor(app.renderer,255,255,255,255);
            SDL_RenderDrawRect(app.renderer,&it.rect);
            roundedRectangleRGBA(app.renderer,it.rect.x-1,it.rect.y-1,it.rect.x+it.rect.w+1,it.rect.y+it.rect.h+1,2,232,237,241,255);
            app.inPaintSpace=false;
            if(it.onButton)
                app.inPaintSpace=true;
        }

        if(it.ID==nameCostumeTextInput)
        {
            if(app.activeCosEdit)
                it.active=true;
            else
                it.active=false;
        }
        if(it.ID==backgroundName)
        {
            if(!app.activeCosEdit)
                it.active=true;
            else
                it.active=false;
        }
    }

    for(auto &it:buttons)
    {
        if(it.ID==xImageTextInput)
        {
            if(!it.text.empty() && it.text!="-")
                app.xImage=std::stoi(it.text);
            else
                app.xImage=0;
            if(app.xImage>app.paintSpace.w/2)
            {
                app.xImage=app.paintSpace.w/2;
                it.text=std::to_string( app.xImage);
            }

            if(app.xImage<-app.paintSpace.w/2)
            {
                app.xImage=-app.paintSpace.w/2;
                it.text="-"+std::to_string( -app.xImage);
            }

        }
        if(it.ID==yImageTextInput)
        {
            if(!it.text.empty() && it.text!="-")
                app.yImage=-std::stoi(it.text);
            else
                app.yImage=0;
            if(app.yImage>app.paintSpace.h/2)
            {
                app.yImage=-app.paintSpace.h/2;
                it.text="-"+std::to_string( -app.yImage);

            }
            if(app.yImage<-app.paintSpace.h/2)
            {
                app.yImage=app.paintSpace.h/2;
                it.text=std::to_string( app.yImage);
            }

        }
        if(it.ID==sizeImageTextInput )
        {
            if(!it.text.empty())
                app.sizeImage=std::stoi(it.text);
            else
                app.sizeImage=100;

        }
        if(app.Confrim)
        {
            if(!app.imageCos.empty())
            {
                app.imageCos[app.imageCos.size()-1].x=app.xImage;
                app.imageCos[app.imageCos.size()-1].y=app.yImage;
                app.imageCos[app.imageCos.size()-1].size=app.sizeImage;
            }
        }
    }

    for(auto &it:buttons)
    {
        if(it.ID==costumeEditor)
        {
            if(it.leftClick)
                app.activeCosEdit=true;
            if(app.activeCosEdit)
            {
                roundedBoxRGBA(app.renderer,it.rect.x-5,it.rect.y-5,it.rect.x+it.rect.w+5,it.rect.y+it.rect.h+5,10,187,180,233,255);
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,5,133,92,214,255);
                roundedBoxRGBA(app.renderer,it.rect.x+2,it.rect.y+2,it.rect.x+it.rect.w-2,it.rect.y+it.rect.h-2,5,255,255,255,255);
                SDL_Rect rec={it.rect.x-1,it.rect.y+it.rect.h*23/32,it.rect.w+2,it.rect.h};
                SDL_RenderSetClipRect(app.renderer,&rec);
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,5,133,92,214,255);
                SDL_RenderSetClipRect(app.renderer,NULL);
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*11/16+it.rect.h*5/32,"Costume","Roman11",SDL_Color{255, 255, 255,255});
            }
            else
            {

                if(it.onButton)
                {
                    roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,5,133,92,214,255);
                    roundedBoxRGBA(app.renderer,it.rect.x+2,it.rect.y+2,it.rect.x+it.rect.w-2,it.rect.y+it.rect.h-2,5,255,255,255,255);
                }
                else
                {
                    roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,5,185,193,206,255);
                    roundedBoxRGBA(app.renderer,it.rect.x+2,it.rect.y+2,it.rect.x+it.rect.w-2,it.rect.y+it.rect.h-2,5,217,227,242,255);
                }
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*11/16+it.rect.h*5/32,"Costume","Roman11",SDL_Color{87, 94, 117,255});
            }

            int w, h;
            SDL_QueryTexture(app.box.t, NULL, NULL, &w, &h);
            SDL_Rect dest={ it.rect.x+it.rect.w/2-w/16,it.rect.y+it.rect.h*12/32 -h/16,w/8,h/8};
            SDL_RenderCopy(app.renderer, app.box.t, NULL, &dest);
        }
        if(it.ID==backgroundEditor)
        {
            if(it.leftClick)
                app.activeCosEdit=false;
            if(!app.activeCosEdit)
            {
                roundedBoxRGBA(app.renderer,it.rect.x-5,it.rect.y-5,it.rect.x+it.rect.w+5,it.rect.y+it.rect.h+5,10,187,180,233,255);
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,5,133,92,214,255);
                roundedBoxRGBA(app.renderer,it.rect.x+2,it.rect.y+2,it.rect.x+it.rect.w-2,it.rect.y+it.rect.h-2,5,255,255,255,255);
                SDL_Rect rec={it.rect.x-1,it.rect.y+it.rect.h*23/32,it.rect.w+2,it.rect.h};
                SDL_RenderSetClipRect(app.renderer,&rec);
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,5,133,92,214,255);
                SDL_RenderSetClipRect(app.renderer,NULL);
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*11/16+it.rect.h*5/32,"Background","Roman11",SDL_Color{255, 255, 255,255});
            }
            else
            {

                if(it.onButton)
                {
                    roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,5,133,92,214,255);
                    roundedBoxRGBA(app.renderer,it.rect.x+2,it.rect.y+2,it.rect.x+it.rect.w-2,it.rect.y+it.rect.h-2,5,255,255,255,255);
                }
                else
                {
                    roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,5,185,193,206,255);
                    roundedBoxRGBA(app.renderer,it.rect.x+2,it.rect.y+2,it.rect.x+it.rect.w-2,it.rect.y+it.rect.h-2,5,217,227,242,255);
                }
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*11/16+it.rect.h*5/32,"Background","Roman11",SDL_Color{87, 94, 117,255});
            }
            int w, h;
            SDL_QueryTexture(app.box.background, NULL, NULL, &w, &h);
            SDL_Rect dest={ it.rect.x+it.rect.w/2-w/16,it.rect.y+it.rect.h*12/32 -h/16,w/8,h/8};
            SDL_RenderCopy(app.renderer, app.box.background, NULL, &dest);
        }


        if(app.activeCosEdit)
       {
         app.boxhelper.t=app.box.t;
       }
        else
        {
            app.boxhelper.t=app.box.background;
        }



        if(3013<=it.ID && it.ID<=3020)
        {
            if(it.leftClick)
            {
                for(auto &it2:app.paint)
                    it2.second=false;
                app.paint[it.ID]=true;
            }
            if(app.paint[it.ID])
            {
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,133,92,214,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,133,92,214,255);
                image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1,it.ID+1000,true);
            }
            else
                image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1,it.ID,true);
        }
        if(3000<=it.ID && it.ID<=3004)
        {
            if(!it.onButton)
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,218,218,218,255);
            }
            else
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,133,92,214,255);
            }
        }
        if(3501 <= it.ID && it.ID <= 3503 && it.active)
        {
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,it.text,"Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==nameCostumeTextInput)
        {
            if(app.activeCosEdit)
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,it.text,"Medium12",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==backgroundName)
        {
            if(!app.activeCosEdit)
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,it.text,"Medium12",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==xImage)
        {
            text(app,it.rect.x-it.rect.w/5,it.rect.y+it.rect.h/2+1,"x","Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==yImage)
        {
            text(app,it.rect.x-it.rect.w/5,it.rect.y+it.rect.h/2+1,"y","Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==sizeImage)
        {
            text(app,it.rect.x-it.rect.w/4,it.rect.y+it.rect.h/2+1,"Size","Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==nameCostume)
        {
            if(app.activeCosEdit)
               text(app,it.rect.x-it.rect.w/4,it.rect.y+it.rect.h/2+2,"Costume","Roman11",SDL_Color{87, 94, 117,255});
            else
                text(app,it.rect.x-it.rect.w*5/16,it.rect.y+it.rect.h/2+2,"Background","Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==flipHorizontal)
        {
            if(it.onButton)
            {
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,7,212,198,241,255);
            }
            if(it.leftClick)
            {
                SDL_SetRenderTarget(app.renderer, app.textureHelperCos);
                SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);
                SDL_RenderClear(app.renderer);
                SDL_RenderCopy(app.renderer, app.boxhelper.t, NULL, NULL);


                SDL_SetRenderTarget(app.renderer, app.boxhelper.t);
                SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);
                SDL_RenderClear(app.renderer);
                SDL_RenderCopyEx(app.renderer, app.textureHelperCos, NULL, NULL,
                                 0.0, NULL, SDL_FLIP_HORIZONTAL);

                SDL_SetRenderTarget(app.renderer, NULL);

            }
            image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/3,1,it.ID,true);
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*3/4,"Flip Horizontal","Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==flipVertical)
        {
            if(it.onButton)
            {
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,7,212,198,241,255);
            }
            if(it.leftClick)
            {
                SDL_SetRenderTarget(app.renderer, app.textureHelperCos);
                SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);
                SDL_RenderClear(app.renderer);
                SDL_RenderCopy(app.renderer, app.boxhelper.t, NULL, NULL);


                SDL_SetRenderTarget(app.renderer, app.boxhelper.t);
                SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);
                SDL_RenderClear(app.renderer);
                SDL_RenderCopyEx(app.renderer, app.textureHelperCos, NULL, NULL,
                                 0.0, NULL, SDL_FLIP_VERTICAL);

                SDL_SetRenderTarget(app.renderer, NULL);
            }
            image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/3,1,it.ID,true);
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*3/4,"Flip Vertical","Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==deleteButton)
        {
            if(it.onButton)
            {
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,7,212,198,241,255);
            }
            if(it.leftClick)
            {
                SDL_SetRenderTarget(app.renderer,app.boxhelper.t);
                SDL_SetRenderDrawColor(app.renderer,0,0,0,0);
                SDL_RenderClear(app.renderer);
                SDL_SetRenderTarget(app.renderer,NULL);
            }
            image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/3,1,it.ID,true);
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*3/4,"Delete","Roman11",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==colorChose)
        {
            if(it.leftClick)
            {
                unsigned char defaultRGB[3] = {
                        app.colorPaint.r,
                        app.colorPaint.g,
                        app.colorPaint.b
                };
                unsigned char resultRGB[3] = { 0, 0, 0 };

                const char* result = tinyfd_colorChooser(
                        "Choose Color",
                        NULL,
                        defaultRGB,
                        resultRGB
                );

                if (result != NULL)
                {
                    app.colorPaint.r = resultRGB[0];
                    app. colorPaint.g = resultRGB[1];
                    app.colorPaint.b = resultRGB[2];
                    app.colorPaint.a = 255;
                }
            }
            roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,7,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
            roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,7,0,0,0,60);
        }
        if(app.paint[eraser])
        {
            if(app.inPaintSpace)
            {
                aacircleRGBA(app.renderer,mouse.x+5,mouse.y+6,20,0,0,0,255);
                aacircleRGBA(app.renderer,mouse.x+5,mouse.y+6,21,0,0,0,255);
                filledCircleRGBA(app.renderer,mouse.x+5,mouse.y+6,20,255,255,255,255);
                if(mouse.leftPressed)
                {
                    int eraseSizeX=30,eraseSizeY=30;
                    SDL_Rect eras={mouse.x-app.xPaint-eraseSizeX/2,mouse.y-app.yPaint-eraseSizeY/2,eraseSizeX,eraseSizeY};

                    SDL_SetRenderTarget(app.renderer,app.boxhelper.t);
                    SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_NONE);

                    SDL_SetRenderDrawColor(app.renderer,0,0,0,0);
                    SDL_RenderFillRect(app.renderer,&eras);
                    SDL_SetRenderDrawBlendMode(app.renderer, SDL_BLENDMODE_BLEND);
                    SDL_SetRenderTarget(app.renderer,NULL);

                }
            }
        }
        if(app.paint[brush])
        {
            if(app.inPaintSpace)
            {
                int brushSize=10;
                filledCircleRGBA(app.renderer,mouse.x,mouse.y,brushSize,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                if(mouse.leftPressed)
                {
                    int eraseSizeX=30,eraseSizeY=30;

                    SDL_SetRenderTarget(app.renderer,app.boxhelper.t);
                    filledCircleRGBA(app.renderer,mouse.x-app.xPaint,mouse.y-app.yPaint,brushSize,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                    SDL_SetRenderTarget(app.renderer,NULL);

                }
            }
        }
        if(app.paint[fill])
        {
            if(app.inPaintSpace)
            {
                if(it.leftClick)
                {
                    if(app.activeCosEdit)
                    {
                        SDL_SetRenderTarget(app.renderer, app.textureHelperCos);
                        SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);
                        SDL_RenderClear(app.renderer);
                        SDL_RenderCopy(app.renderer, app.boxhelper.t, NULL, NULL);


                        SDL_SetRenderTarget(app.renderer, app.boxhelper.t);
                        SDL_SetRenderDrawColor(app.renderer, app.colorPaint.r, app.colorPaint.g, app.colorPaint.b, app.colorPaint.a);
                        SDL_RenderClear(app.renderer);
                        SDL_RenderCopy(app.renderer,app.textureHelperCos, NULL, NULL);
                        SDL_SetRenderTarget(app.renderer, NULL);
                    }
                    else
                    {
                        SDL_SetRenderTarget(app.renderer, app.boxhelper.t);
                        SDL_SetRenderDrawColor(app.renderer, app.colorPaint.r, app.colorPaint.g, app.colorPaint.b, app.colorPaint.a);
                        SDL_RenderClear(app.renderer);
                        SDL_SetRenderTarget(app.renderer, NULL);
                    }

                }
            }
        }
        if(app.paint[lineS])
        {
            int lineThiks=5;
            if(app.inPaintSpace &&  mouse.leftDown)
            {
                app.isShaping=true;
            }
            if(app.isShaping && app.inPaintSpace)
            {
                aalineRGBA(app.renderer,mouse.xLeftDown,mouse.yLeftDown,mouse.x,mouse.y,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                aalineRGBA(app.renderer,mouse.xLeftDown+1,mouse.yLeftDown,mouse.x,mouse.y+1,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                aalineRGBA(app.renderer,mouse.xLeftDown,mouse.yLeftDown+1,mouse.x+1,mouse.y,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
            }
            if(app.isShaping && app.inPaintSpace && mouse.leftUp)
            {
                SDL_SetRenderTarget(app.renderer, app.boxhelper.t);
                aalineRGBA(app.renderer,mouse.xLeftDown-app.xPaint,mouse.yLeftDown-app.yPaint,mouse.x-app.xPaint,mouse.y-app.yPaint,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                aalineRGBA(app.renderer,mouse.xLeftDown-app.xPaint+1,mouse.yLeftDown-app.yPaint,mouse.x-app.xPaint+1,mouse.y-app.yPaint,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                aalineRGBA(app.renderer,mouse.xLeftDown-app.xPaint,mouse.yLeftDown-app.yPaint+1,mouse.x-app.xPaint,mouse.y-app.yPaint+1,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                SDL_SetRenderTarget(app.renderer,NULL);
            }
            if(mouse.leftUp)
            {
                app.isShaping=false;
            }

        }
        if(app.paint[circle])
        {

            if(app.inPaintSpace &&  mouse.leftDown)
            {
                app.isShaping=true;
            }
            if(app.isShaping && app.inPaintSpace)
            {
                for(auto &it2:buttons)
                    if(it2.ID==showSpace)
                    {
                        if( (mouse.xLeftDown+sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))) <= (it2.rect.x+it2.rect.w) && (mouse.xLeftDown-sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))) >= (it2.rect.x))
                            if( (mouse.yLeftDown+sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))) <= (it2.rect.y+it2.rect.h) && (mouse.yLeftDown-sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))) >= (it2.rect.y))
                            {
                                aacircleRGBA(app.renderer,mouse.xLeftDown,mouse.yLeftDown,sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown)),app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                                aacircleRGBA(app.renderer,mouse.xLeftDown,mouse.yLeftDown,sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))+1,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                                aacircleRGBA(app.renderer,mouse.xLeftDown,mouse.yLeftDown,sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))-1,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                            }
                        break;
                    }
            }
            if(app.isShaping && app.inPaintSpace && mouse.leftUp)
            {
                for(auto &it2:buttons)
                    if(it2.ID==showSpace)
                    {
                        if( (mouse.xLeftDown+sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))) <= (it2.rect.x+it2.rect.w) && (mouse.xLeftDown-sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))) >= (it2.rect.x))
                            if( (mouse.yLeftDown+sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))) <= (it2.rect.y+it2.rect.h) && (mouse.yLeftDown-sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))) >= (it2.rect.y))
                            {
                                SDL_SetRenderTarget(app.renderer, app.boxhelper.t);
                                aacircleRGBA(app.renderer,mouse.xLeftDown-app.xPaint,mouse.yLeftDown-app.yPaint,sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown)),app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                                aacircleRGBA(app.renderer,mouse.xLeftDown-app.xPaint,mouse.yLeftDown-app.yPaint,sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))+1,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                                aacircleRGBA(app.renderer,mouse.xLeftDown-app.xPaint,mouse.yLeftDown-app.yPaint,sqrt((mouse.x-mouse.xLeftDown)*(mouse.x-mouse.xLeftDown)+(mouse.y-mouse.yLeftDown)*(mouse.y-mouse.yLeftDown))-1,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                                SDL_SetRenderTarget(app.renderer,NULL);
                            }
                        break;
                    }

            }
            if(mouse.leftUp)
            {
                app.isShaping=false;
            }

        }
        if(app.paint[rectangle])
        {
            int lineThiks=5;
            if(app.inPaintSpace &&  mouse.leftDown)
            {
                app.isShaping=true;
            }
            if(app.isShaping && app.inPaintSpace)
            {
                SDL_Rect movaghat1= {mouse.xLeftDown, mouse.yLeftDown, mouse.x - mouse.xLeftDown, mouse.y - mouse.yLeftDown};
                SDL_Rect movaghat2= {mouse.xLeftDown+1, mouse.yLeftDown+1, mouse.x - mouse.xLeftDown, mouse.y - mouse.yLeftDown};
                SDL_Rect movaghat3= {mouse.xLeftDown-1, mouse.yLeftDown-1, mouse.x - mouse.xLeftDown, mouse.y - mouse.yLeftDown};
                SDL_SetRenderDrawColor(app.renderer,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                SDL_RenderDrawRect(app.renderer,&movaghat1);
                SDL_RenderDrawRect(app.renderer,&movaghat2);
                SDL_RenderDrawRect(app.renderer,&movaghat3);
            }

            if(app.isShaping && app.inPaintSpace && mouse.leftUp)
            {
                SDL_SetRenderTarget(app.renderer, app.boxhelper.t);
                SDL_Rect Movaghat1= {mouse.xLeftDown-app.xPaint, mouse.yLeftDown-app.yPaint, mouse.x - mouse.xLeftDown, mouse.y - mouse.yLeftDown};
                SDL_Rect Movaghat2= {mouse.xLeftDown+1-app.xPaint, mouse.yLeftDown+1-app.yPaint, mouse.x - mouse.xLeftDown, mouse.y - mouse.yLeftDown};
                SDL_Rect Movaghat3= {mouse.xLeftDown-1-app.xPaint, mouse.yLeftDown-1-app.yPaint, mouse.x - mouse.xLeftDown, mouse.y - mouse.yLeftDown};
                SDL_SetRenderDrawColor(app.renderer,app.colorPaint.r,app.colorPaint.g,app.colorPaint.b,app.colorPaint.a);
                SDL_RenderDrawRect(app.renderer,&Movaghat1);
                SDL_RenderDrawRect(app.renderer,&Movaghat2);
                SDL_RenderDrawRect(app.renderer,&Movaghat3);
                SDL_SetRenderTarget(app.renderer,NULL);
            }
            if(mouse.leftUp)
            {
                app.isShaping=false;
            }

        }
        if(it.ID==uploadImage)
        {
            if(app.Confrim && it.leftClick && !app.imageCos.empty())
            {
                SDL_Rect clip={0,0,app.paintSpace.w,app.paintSpace.h};
                SDL_RenderSetClipRect(app.renderer, &clip);
                SDL_SetRenderTarget(app.renderer, app.boxhelper.t);
                SDL_Rect dst={
                        app.paintSpace.w/2+app.imageCos[app.imageCos.size()-1].x-( app.imageCos[app.imageCos.size()-1].w * app.imageCos[app.imageCos.size()-1].size / 100)/2,
                        app.paintSpace.h/2+app.imageCos[app.imageCos.size()-1].y-(app.imageCos[app.imageCos.size()-1].h * app.imageCos[app.imageCos.size()-1].size / 100)/2,
                        app.imageCos[app.imageCos.size()-1].w * app.imageCos[app.imageCos.size()-1].size / 100,
                        app.imageCos[app.imageCos.size()-1].h * app.imageCos[app.imageCos.size()-1].size / 100
                };
                SDL_RenderCopy(app.renderer, app.imageCos[app.imageCos.size()-1].texture, NULL, &dst);
                SDL_SetRenderTarget(app.renderer, NULL);
                SDL_RenderSetClipRect(app.renderer, NULL);
                app.imageCos.pop_back();
                if(app.imageCos.empty())
                    app.Confrim=false;

                for(auto &it:buttons)
                {
                    if(it.ID==xImageTextInput)
                        it.text="0";
                    if(it.ID==yImageTextInput)
                        it.text="0";
                    if(it.ID==sizeImageTextInput )
                        it.text="100";
                }


            }
            else if(!app.Confrim && it.leftClick)
            {
                const char* filterPatterns[] = { "*.png", "*.jpg" };
                const char* filePaths = tinyfd_openFileDialog(
                        "Select Images",
                        "",
                        2,
                        filterPatterns,
                        "Image Files",
                        1                    // ← چند فایل
                );
                if(filePaths!=NULL)
                {
                    std::vector<std::string> paths;
                    std::stringstream ss(filePaths);
                    std::string path;

                    while (std::getline(ss, path, '|'))
                    {
                        paths.push_back(path);
                    }
                    for (int i = 0; i < paths.size(); i++)
                    {
                        SDL_Surface* surface = IMG_Load(paths[i].c_str());
                        if (surface != NULL)
                        {
                            SDL_Texture* texture = SDL_CreateTextureFromSurface(app.renderer, surface);
                            if (texture != NULL)
                            {
                                UploadedImageCostume img;
                                img.texture = texture;
                                img.w = surface->w;
                                img.h = surface->h;
                                img.path = paths[i];
                                app.imageCos.push_back(img);
                            }

                            SDL_FreeSurface(surface);
                        }
                    }

                    app.Confrim=true;
                }
            }

            if(app.Confrim && !app.imageCos.empty())
            {
                SDL_RenderSetClipRect(app.renderer, &app.paintSpace);
                for(auto it:app.imageCos)
                {
                    SDL_Rect dst={
                            app.paintSpace.x +app.paintSpace.w/2+ it.x-(it.w*it.size/100)/2,
                            app.paintSpace.y +app.paintSpace.h/2+ it.y-(it.h*it.size/ 100)/2,
                            it.w * it.size/ 100,
                            it.h*it.size/ 100};
                    SDL_RenderCopy(app.renderer, it.texture, NULL, &dst);
                }
                SDL_RenderSetClipRect(app.renderer, NULL);
            }
            if(!app.Confrim)
            {
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,"Upload Image","Bold12",SDL_Color{87, 94, 117,255});
            }
            if(app.Confrim)
            {
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15, 76, 191, 86, 255);
                if(!it.onButton)
                {
                    roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,217,217,217, 255);
                }
                else
                {
                    roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,133,92,214,255);
                }
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,"Confrim","Bold12",SDL_Color{255, 255, 255, 255});
            }

        }
        if(it.ID==save)
        {
            if(!app.activeCosEdit)
            {
                if(!it.onButton)
                {
                    roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,218,218,218,255);
                }
                else
                {
                    roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,133,92,214,255);
                }
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,"Save","Bold12",SDL_Color{87, 94, 117,255});
                if(it.leftClick)
                {
                    std::string name;
                    for(auto &it2:buttons)
                    {
                        if(it2.ID==backgroundName)
                        {
                            name=it2.text;
                            break;
                        }
                    }
                   name+=".png";
                    const char *filters[] = {"*.png"};

                    const char *savePath = tinyfd_saveFileDialog(
                            "Save Image",
                            name.c_str(),
                            1,
                            filters,
                            "PNG Files"
                    );

                    if (savePath != NULL)
                    {
                        int w,h;
                        SDL_QueryTexture(app.boxhelper.t, NULL, NULL, &w, &h);
                        SDL_Surface *sur = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
                        SDL_Texture *tex = SDL_CreateTexture(app.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
                        SDL_SetRenderTarget(app.renderer, tex);
                        SDL_RenderCopy(app.renderer, app.boxhelper.t, NULL, NULL);
                        SDL_RenderReadPixels(app.renderer, NULL, SDL_PIXELFORMAT_RGBA32, sur->pixels, sur->pitch);
                        SDL_SetRenderTarget(app.renderer, NULL);
                        SDL_DestroyTexture(tex);
                        IMG_SavePNG(sur, (savePath));
                        SDL_FreeSurface(sur);
                    }
                }
            }
        }
        if(it.ID==saveLibrary)
        {
            if(!app.activeCosEdit)
            {
                if(!it.onButton)
                {
                    roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,218,218,218,255);
                }
                else
                {
                    roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,133,92,214,255);
                }
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,"Save in Library","Bold12",SDL_Color{87, 94, 117,255});
                if(it.leftClick)
                {
                    int w,h;
                    SDL_QueryTexture(app.boxhelper.t, NULL, NULL, &w, &h);
                    SDL_Surface *sur = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
                    SDL_Texture *tex = SDL_CreateTexture(app.renderer, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, w, h);
                    SDL_SetRenderTarget(app.renderer, tex);
                    SDL_RenderCopy(app.renderer, app.boxhelper.t, NULL, NULL);
                    SDL_RenderReadPixels(app.renderer, NULL, SDL_PIXELFORMAT_RGBA32, sur->pixels, sur->pitch);
                    SDL_SetRenderTarget(app.renderer, NULL);
                    SDL_DestroyTexture(tex);
                    for(auto &it2:buttons)
                    {
                        if(it2.ID==backgroundName)
                        {
                            IMG_SavePNG(sur, ("backgroundLibrary\\" + it2.text + ".png").c_str());
                            break;
                        }
                    }
                    SDL_FreeSurface(sur);
                    loadPNGLibrary(app);
                }
            }
        }


        if(app.activeCosEdit)
       {
            app.box.t= app.boxhelper.t;
        }
        else
        {
            app.box.background= app.boxhelper.t;
            SetBackground(app,app.box.background,app.box.backgroundStage);
        }

    }









}
void textureRenderer(AppState &app,std::vector<AllTabButtons> &tabs,float x,float y,float scale)
{
    for(auto &it1:tabs)
    {
        if(it1.ID==TAB_COSTUMES)
            for(auto &it2:it1.buttons)
            {
                if(it2.ID==showSpace)
                {
                    int imageW,imageH;
                    SDL_Rect rect;
                    SDL_Rect scr;
                    scr.x=0;
                    scr.y=0;
                    scr.w=imageW=it2.rect.w;
                    scr.h=imageH=it2.rect.h;
                    rect.x=x-(double)imageW/scale/2.0;
                    rect.y=y-(double)imageH/scale/2.0;
                    rect.w=(double)scr.w/scale;
                    rect.h=(double)scr.h/scale;

                    if(app.activeCosEdit)
                        SDL_RenderCopy(app.renderer,app.box.t,&scr,&rect);
                    else
                        SDL_RenderCopy(app.renderer,app.box.background,&scr,&rect);
                    break;
                }
            }
    }
}
void SaveProject(AppState &app)
{
    const char* filters[] = {"*.scrp","*.json"};
    const char* path = tinyfd_saveFileDialog(
            "Save Project",
            "project.scrp",
            2,
            filters,            // فیلترها
            "Scratch Project"   // توضیح فیلتر
    );
    if(!path)
        return;

    json j;

    j["block"] = json::array();
    for (auto &it:app.block) {
        json a;
        a["index"] = it.index;
        a["ID"] = it.ID;
        a["type"] = it.type;
        a["rect"]["x"] = it.rect.x;
        a["rect"]["y"] = it.rect.y;
        a["rect"]["w"] = it.rect.w;
        a["rect"]["h"] = it.rect.h;
        a["rectText1"]["x"] = it.rectText1.x;
        a["rectText1"]["y"] = it.rectText1.y;
        a["rectText1"]["w"] = it.rectText1.w;
        a["rectText1"]["h"] = it.rectText1.h;
        a["rectText2"]["x"] = it.rectText2.x;
        a["rectText2"]["y"] = it.rectText2.y;
        a["rectText2"]["w"] = it.rectText2.w;
        a["rectText2"]["h"] = it.rectText2.h;
        a["p1"]=it.p1;
        a["p2"]=it.p2;
        if (!it.child.empty()) {
            a["child"] = json::array();
            for (auto &it2: it.child) {
                json b;

                b["index"] = it2.index;
                b["ID"] = it2.ID;
                b["type"] = it2.type;
                b["indexParents"] = it2.indexParents;
                b["rect"]["x"] = it2.rect.x;
                b["rect"]["y"] = it2.rect.y;
                b["rect"]["w"] = it2.rect.w;
                b["rect"]["h"] = it2.rect.h;
                b["rectText1"]["x"] = it2.rectText1.x;
                b["rectText1"]["y"] = it2.rectText1.y;
                b["rectText1"]["w"] = it2.rectText1.w;
                b["rectText1"]["h"] = it2.rectText1.h;
                b["rectText2"]["x"] = it2.rectText2.x;
                b["rectText2"]["y"] = it2.rectText2.y;
                b["rectText2"]["w"] = it2.rectText2.w;
                b["rectText2"]["h"] = it2.rectText2.h;
                b["p1"]=it2.p1;
                b["p2"]=it2.p2;

                a["child"].push_back(b);
            }
        }
        j["block"].push_back(a);
    }

    j["allBlock"] = json::array();
    for (auto &it:app.allblock) {
        json a;
        a["index"] = it.index;
        a["ID"] = it.ID;
        a["type"] = it.type;
        a["rect"]["x"] = it.rect.x;
        a["rect"]["y"] = it.rect.y;
        a["rect"]["w"] = it.rect.w;
        a["rect"]["h"] = it.rect.h;
        a["rectText1"]["x"] = it.rectText1.x;
        a["rectText1"]["y"] = it.rectText1.y;
        a["rectText1"]["w"] = it.rectText1.w;
        a["rectText1"]["h"] = it.rectText1.h;
        a["rectText2"]["x"] = it.rectText2.x;
        a["rectText2"]["y"] = it.rectText2.y;
        a["rectText2"]["w"] = it.rectText2.w;
        a["rectText2"]["h"] = it.rectText2.h;
        a["p1"]=it.p1;
        a["p2"]=it.p2;
        if (!it.child.empty()) {
            a["child"] = json::array();
            for (auto &it2: it.child) {
                json b;

                b["index"] = it2.index;
                b["ID"] = it2.ID;
                b["type"] = it2.type;
                b["indexParents"] = it2.indexParents;
                b["rect"]["x"] = it2.rect.x;
                b["rect"]["y"] = it2.rect.y;
                b["rect"]["w"] = it2.rect.w;
                b["rect"]["h"] = it2.rect.h;
                b["rectText1"]["x"] = it2.rectText1.x;
                b["rectText1"]["y"] = it2.rectText1.y;
                b["rectText1"]["w"] = it2.rectText1.w;
                b["rectText1"]["h"] = it2.rectText1.h;
                b["rectText2"]["x"] = it2.rectText2.x;
                b["rectText2"]["y"] = it2.rectText2.y;
                b["rectText2"]["w"] = it2.rectText2.w;
                b["rectText2"]["h"] = it2.rectText2.h;
                b["p1"]=it2.p1;
                b["p2"]=it2.p2;

                a["child"].push_back(b);
            }
        }
        j["allBlock"].push_back(a);
    }

    j["box"]["x"] = app.box.x;
    j["box"]["y"] = app.box.y;
    j["box"]["w"] = app.box.w;
    j["box"]["h"] = app.box.h;
    j["box"]["angle"] = app.box.angle;
    j["box"]["stop"] = app.box.stop;
    j["box"]["scale"] = app.box.scale;
    int w,h;
    SDL_QueryTexture(app.box.t, NULL, NULL, &w, &h);
    j["box"]["textureW"]=w;
    j["box"]["textureH"]=h;
    j["box"]["texture"] =textureToBase64(app.renderer,app.box.t);
    j["box"]["backgroundName"]=app.box.backgroundName;
    int w2,h2;
    SDL_QueryTexture(app.box.background, NULL, NULL, &w2, &h2);
    j["box"]["backgroundW"]=w2;
    j["box"]["backgroundH"]=h2;
    j["box"]["background"] =textureToBase64(app.renderer,app.box.background);

    std::string jsonStr = j.dump(4);

    std::ofstream file(path, std::ios::binary);
    if (file.is_open())
    {
        file.write(jsonStr.c_str(), jsonStr.size());
        file.close();
    }

}
std::string textureToBase64(SDL_Renderer* renderer, SDL_Texture* texture) {

    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);


    SDL_SetRenderTarget(renderer, texture);

    std::vector<unsigned char> pixels(w * h * 4);
    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ABGR8888, pixels.data(), w * 4);

    SDL_SetRenderTarget(renderer, NULL);

    const char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    unsigned char* data = pixels.data();
    int dataSize = pixels.size();

    std::string result;
    result.reserve((dataSize + 2) / 3 * 4);

    for (int i = 0; i < dataSize; i += 3) {
        unsigned int b = (data[i] << 16);
        if (i + 1 < dataSize) b |= (data[i + 1] << 8);
        if (i + 2 < dataSize) b |= data[i + 2];

        result += table[(b >> 18) & 0x3F];
        result += table[(b >> 12) & 0x3F];
        result += (i + 1 < dataSize) ? table[(b >> 6) & 0x3F] : '=';
        result += (i + 2 < dataSize) ? table[b & 0x3F] : '=';
    }

    return result;
}
SDL_Texture* base64ToTexture(SDL_Renderer* renderer, const std::string& base64Str, int w, int h) {
    const std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) {
        T[chars[i]] = i;
    }

    std::vector<unsigned char> pixels;
    int val = 0, bits = 0;
    for (unsigned char c : base64Str) {
        if (T[c] == -1) continue;
        val = (val << 6) + T[c];
        bits += 6;
        if (bits >= 8) {
            bits -= 8;
            pixels.push_back((val >> bits) & 0xFF);
        }
    }

    if (pixels.size() != (size_t)(w * h * 4)) {
        printf("Error: pixel data size mismatch! expected %d, got %zu\n", w * h * 4, pixels.size());
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_ABGR8888,
            SDL_TEXTUREACCESS_TARGET,
            w, h
    );

    if (!texture) {
        printf("Error creating texture: %s\n", SDL_GetError());
        return nullptr;
    }

    SDL_UpdateTexture(texture, NULL, pixels.data(), w * 4);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

    return texture;
}
void LoadProject(AppState& app)
{
    const char* filters[] = {"*.scrp", "*.json","*.*"};
    const char* filePath = tinyfd_openFileDialog(
            "Open Project",
            "",
            3,
            filters,
            "Scratch Project",
            0
    );

    if (!filePath)
        return;

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        SDL_MessageBoxButtonData buttons[] = {
                {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "OK"}
        };
        SDL_MessageBoxData msgBox = {
                SDL_MESSAGEBOX_WARNING,
                app.window,
                "Load Failed",
                "Failed to open file",
                1,
                buttons,
                NULL
        };
        int buttonId = -1;
        SDL_ShowMessageBox(&msgBox, &buttonId);
        if(buttonId==0)
            return;
    }


    json j;
    file >> j;
    file.close();


    app.block.clear();
    app.allblock.clear();
    if (app.box.t)
    {
        SDL_DestroyTexture(app.box.t);
        app.box.t = nullptr;
    }

    if(!j.contains("block") && !(j.contains("allBlock")) && !(j.contains("box")))
    {
        SDL_MessageBoxButtonData buttons[] = {
                {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "OK"}
        };
        SDL_MessageBoxData msgBox = {
                SDL_MESSAGEBOX_WARNING,
                app.window,
                "Load Failed",
                "Invalid file format!\\nThis file is not Scratch project",
                1,
                buttons,
                NULL
        };
        int buttonId = -1;
        SDL_ShowMessageBox(&msgBox, &buttonId);
        if(buttonId==0)
            return;
    }
    if (j.contains("block"))
    {
        for (auto &it: j["block"]) {
            Block a;
            a.index = it["index"];
            a.ID = it["ID"];
            a.type = it["type"];
            a.rect.x = it["rect"]["x"];
            a.rect.y = it["rect"]["y"];
            a.rect.w = it["rect"]["w"];
            a.rect.h = it["rect"]["h"];
            a.rectText1.x = it["rectText1"]["x"];
            a.rectText1.y = it["rectText1"]["y"];
            a.rectText1.w = it["rectText1"]["w"];
            a.rectText1.h = it["rectText1"]["h"];
            a.rectText2.x = it["rectText2"]["x"];
            a.rectText2.y = it["rectText2"]["y"];
            a.rectText2.w = it["rectText2"]["w"];
            a.rectText2.h = it["rectText2"]["h"];
            a.p1 = it["p1"];
            a.p2 = it["p2"];
            if (it.contains("child")) {
                for (auto &it2: it["child"]) {
                    Children b;
                    b.index = it2["index"];
                    b.ID = it2["ID"];
                    b.type = it2["type"];
                    b.rect.x = it2["rect"]["x"];
                    b.rect.y = it2["rect"]["y"];
                    b.rect.w = it2["rect"]["w"];
                    b.rect.h = it2["rect"]["h"];
                    b.rectText1.x = it2["rectText1"]["x"];
                    b.rectText1.y = it2["rectText1"]["y"];
                    b.rectText1.w = it2["rectText1"]["w"];
                    b.rectText1.h = it2["rectText1"]["h"];
                    b.rectText2.x = it2["rectText2"]["x"];
                    b.rectText2.y = it2["rectText2"]["y"];
                    b.rectText2.w = it2["rectText2"]["w"];
                    b.rectText2.h = it2["rectText2"]["h"];
                    b.p1 = it2["p1"];
                    b.p2 = it2["p2"];

                    a.child.push_back(b);
                }
            }
            app.block.push_back(a);
        }
    }
    if (j.contains("allBlock"))
    {
        for (auto &it: j["allBlock"]) {
            Block a;
            a.index = it["index"];
            a.ID = it["ID"];
            a.type = it["type"];
            a.rect.x = it["rect"]["x"];
            a.rect.y = it["rect"]["y"];
            a.rect.w = it["rect"]["w"];
            a.rect.h = it["rect"]["h"];
            a.rectText1.x = it["rectText1"]["x"];
            a.rectText1.y = it["rectText1"]["y"];
            a.rectText1.w = it["rectText1"]["w"];
            a.rectText1.h = it["rectText1"]["h"];
            a.rectText2.x = it["rectText2"]["x"];
            a.rectText2.y = it["rectText2"]["y"];
            a.rectText2.w = it["rectText2"]["w"];
            a.rectText2.h = it["rectText2"]["h"];
            a.p1 = it["p1"];
            a.p2 = it["p2"];
            if (it.contains("child")) {
                for (auto &it2: it["child"]) {
                    Children b;
                    b.index = it2["index"];
                    b.ID = it2["ID"];
                    b.type = it2["type"];
                    b.rect.x = it2["rect"]["x"];
                    b.rect.y = it2["rect"]["y"];
                    b.rect.w = it2["rect"]["w"];
                    b.rect.h = it2["rect"]["h"];
                    b.rectText1.x = it2["rectText1"]["x"];
                    b.rectText1.y = it2["rectText1"]["y"];
                    b.rectText1.w = it2["rectText1"]["w"];
                    b.rectText1.h = it2["rectText1"]["h"];
                    b.rectText2.x = it2["rectText2"]["x"];
                    b.rectText2.y = it2["rectText2"]["y"];
                    b.rectText2.w = it2["rectText2"]["w"];
                    b.rectText2.h = it2["rectText2"]["h"];
                    b.p1 = it2["p1"];
                    b.p2 = it2["p2"];

                    a.child.push_back(b);
                }
            }
            app.allblock.push_back(a);
        }
    }
    if(j.contains("box"))
    {
        app.box.x=j["box"]["x"];
        app.box.y=j["box"]["y"];
        app.box.w=j["box"]["w"];
        app.box.h=j["box"]["h"];
        app.box.angle=j["box"]["angle"];
        app.box.stop=j["box"]["stop"];
        app.box.scale=j["box"]["scale"];

        app.box.w=j["box"]["textureW"];
        app.box.h=j["box"]["textureH"];
        app.box.t=base64ToTexture(app.renderer,j["box"]["texture"].get<std::string>(),j["box"]["textureW"],j["box"]["textureH"]);
        app.box.backgroundName=j["box"]["backgroundName"];
        int w2,h2;
        w2=j["box"]["backgroundW"];
        h2=j["box"]["backgroundH"];
        app.box.background=base64ToTexture(app.renderer,j["box"]["background"].get<std::string>(),w2,h2);

        app.box.w/=2;
        app.box.h/=2;
    }

}
void RenderExtensionTab(std::vector<AllTabButtons> &tabs,std::vector<ButtonRect> &buttons,AppState &app,ThemeCodeTab &color,TabTexture &texture)
{
    SDL_SetRenderDrawColor(app.renderer,233,241,252,255);
    SDL_RenderClear(app.renderer);


    for(auto &it:buttons)
    {
        if(it.ID==BackExtension)
        {
            SDL_Rect rect={0,0,app.W,it.rect.h};
            SDL_SetRenderDrawColor(app.renderer,133,92,214,255);
            SDL_RenderFillRect(app.renderer,&rect);
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,"Back","Medium16",SDL_Color{255,255,255,255});
            text(app,app.W/2,it.rect.y+it.rect.h/2,"Choose an Extension","Roman18",SDL_Color{255,255,255,255});
            if(it.leftClick)
            {
                for(auto &it2:tabs)
                {
                    if(it2.ID==TAB_GENERAL)
                        it2.active=true;
                    if(it2.ID==TAB_CODE)
                        it2.active=true;
                    if(it2.ID==TAB_EXTENSION)
                        it2.active= false;
                }
            }
            app.isOnBlock=false;
            if(it.onButton)
            {
                app.isOnBlock=true;
            }
        }
        if(it.ID==CLOSE_BUTTONExtension)
        {
            if(it.onButton)
            {
                SDL_SetRenderDrawColor(app.renderer,232,17,35,255);
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
            }
            int L=6;
            aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-L/ sqrt(2),it.rect.y+it.rect.h/2-L/sqrt(2),it.rect.x+it.rect.w/2+L/sqrt(2),it.rect.y+it.rect.h/2+L/sqrt(2),214,214,214,255);
            aalineRGBA(app.renderer,(it.rect.x+it.rect.w/2-L/ sqrt(2)),(it.rect.y+it.rect.h/2+L/sqrt(2)),(it.rect.x+it.rect.w/2+L/sqrt(2)),(it.rect.y+it.rect.h/2-L/sqrt(2)),214,214,214,255);
            aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-L/ sqrt(2),it.rect.y+it.rect.h/2-L/sqrt(2)-1,it.rect.x+it.rect.w/2+L/sqrt(2),it.rect.y+it.rect.h/2+L/sqrt(2)-1,214,214,214,255);
            aalineRGBA(app.renderer,(it.rect.x+it.rect.w/2-L/ sqrt(2)),(it.rect.y+it.rect.h/2+L/sqrt(2))-1,(it.rect.x+it.rect.w/2+L/sqrt(2)),(it.rect.y+it.rect.h/2-L/sqrt(2))-1,214,214,214,255);
        }
        if(it.ID==WINDOW_BUTTONExtension)
        {
            if(it.active)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,122, 86, 199, 255);
                    SDL_RenderFillRect(app.renderer,&it.rect);
                }
                SDL_SetRenderDrawColor(app.renderer,214,214,214,255);
                SDL_Rect rectWindow={it.rect.x+it.rect.w/2-it.rect.w/10,it.rect.y+it.rect.h/2-it.rect.w/10,it.rect.w*2/10,it.rect.w*2/10};
                SDL_RenderDrawRect(app.renderer,&rectWindow);
            }
        }
        if(it.ID==MINIMIZED_BUTTONExtension)
        {
            if(it.active)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,122, 86, 199, 255);
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
        if(it.ID==PenExtension)
        {
            roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,255,255,255,255);
            image(app,it.rect.x,it.rect.y,1,PenPhoto);
            inverseRoundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,233,241,252,255);
            roundedBoxRGBA(app.renderer,it.rect.x+16,it.rect.y+147,it.rect.x+20+52,it.rect.y+151+52,5,255,255,255,255);
            roundedBoxRGBA(app.renderer,it.rect.x+20,it.rect.y+151,it.rect.x+20+48,it.rect.y+151+48,5,15,189,140,255);
            image(app,it.rect.x+20+24,it.rect.y+151+24,1,PenExtension,true);
            if(!it.onButton)
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,217,217,217,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+1,it.rect.y+it.rect.h+1,8,217,217,217,255);
                roundedRectangleRGBA(app.renderer,it.rect.x-1,it.rect.y-1,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,217,217,217,255);
            }
            else
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,133,92,214,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+1,it.rect.y+it.rect.h+1,8,133,92,214,255);
                roundedRectangleRGBA(app.renderer,it.rect.x-1,it.rect.y-1,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,133,92,214,255);
            }
            text(app,it.rect.x+20,it.rect.y+it.rect.h*184/245,"Pen","Bold19",SDL_Color{86,89,111,255}, true);
            text(app,it.rect.x+20,it.rect.y+it.rect.h*208/245,"Draw with your sprites.","Roman19",SDL_Color{86,89,111,255}, true);
            if(it.leftClick)
            {
                app.activeExtention=true;
                for(auto &it2:tabs)
                {
                    if(it2.ID==TAB_GENERAL)
                        it2.active=true;
                    if(it2.ID==TAB_CODE)
                    {
                        it2.active=true;
                        RenderTextureCodeTab(it2.buttons, app, color, texture);
                    }
                    if(it2.ID==TAB_EXTENSION)
                        it2.active=false;
                }
            }
        }
    }



}
void UpdateSpriteState(std::vector<AllTabButtons> &tabs,AppState &app)
{
    if(app.engineRunning)
    {
        for(auto &it1:tabs)
            if(it1.ID==TAB_GENERAL)
            {
                for(auto &it2:it1.buttons)
                {
                    if(it2.ID==xSpriteTextInput)
                    {
                        it2.text=std::to_string(int(app.box.x));

                    }
                    if(it2.ID==ySpriteTextInput)
                    {
                        it2.text= std::to_string(int(app.box.y));
                    }
                    if(it2.ID==sizeSpriteTextInput)
                    {
                        it2.text= std::to_string(int(app.box.scale));
                    }
                    if(it2.ID==directionSpriteTextInput)
                    {
                        it2.text= std::to_string(int(app.box.angle));
                    }
                }

            }

    }
    else
    {
        for(auto &it1:tabs)
            if(it1.ID==TAB_GENERAL)
            {
                for(auto &it2:it1.buttons)
                {
                    if(it2.ID==xSpriteTextInput)
                    {
                        if(it2.text.empty()|| it2.text=="-")
                            app.box.x=0;
                        else
                        {
                            if(std::stoi(it2.text)>app.stageRect.w/2)
                            {
                                app.box.x=app.stageRect.w/2;
                                it2.text=std::to_string(int(app.box.x));
                            }

                            else if(std::stoi(it2.text)<-app.stageRect.w/2)
                            {
                                app.box.x=-app.stageRect.w/2;
                                it2.text=std::to_string(int(app.box.x));
                            }

                            else
                                app.box.x=std::stoi(it2.text);

                        }

                    }
                    if(it2.ID==ySpriteTextInput)
                    {
                        if(it2.text.empty() || it2.text=="-")
                            app.box.y=0;
                        else
                        {
                            if(std::stoi(it2.text)>app.stageRect.h/2)
                            {
                                app.box.y=app.stageRect.h/2;
                                it2.text=std::to_string(int(app.box.y));
                            }

                            else if(std::stoi(it2.text)<-app.stageRect.h/2)
                            {
                                app.box.y=-app.stageRect.h/2;
                                it2.text=std::to_string(int(app.box.y));
                            }

                            else
                                app.box.y=std::stoi(it2.text);

                        }

                    }
                    if(it2.ID==sizeSpriteTextInput)
                    {
                        if(it2.text.empty() || it2.text=="-")
                            app.box.scale=100;
                        else
                        {
                            app.box.scale=std::stoi(it2.text);
                        }

                    }
                    if(it2.ID==directionSpriteTextInput)
                    {
                        if(it2.text.empty()|| it2.text=="-")
                            app.box.angle=90;
                        else
                        {
                            app.box.angle=std::stoi(it2.text);
                        }
                    }
                }

            }
    }
}
void RenderGalleryTab(std::vector<AllTabButtons> &tabs,std::vector<ButtonRect> &buttons,AppState &app,ThemeCodeTab &color,TabTexture &texture)
{
    if(LibraryChanged(app))
    {
        loadPNGLibrary(app);
    }


    SDL_SetRenderDrawColor(app.renderer,233,241,252,255);
    SDL_RenderClear(app.renderer);



    for(auto &it:buttons)
    {
        if(it.ID==BackGallery)
        {
            SDL_Rect rect={0,0,app.W,it.rect.h};
            SDL_SetRenderDrawColor(app.renderer,133,92,214,255);
            SDL_RenderFillRect(app.renderer,&rect);
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,"Back","Medium16",SDL_Color{255,255,255,255});
            text(app,app.W/2,it.rect.y+it.rect.h/2,"Choose an Backdrop","Roman18",SDL_Color{255,255,255,255});
            if(it.leftClick)
            {
                for(auto &it2:tabs)
                {
                    if(it2.ID==TAB_GENERAL)
                        it2.active=true;
                    if(it2.ID==TAB_CODE)
                        it2.active=true;
                    if(it2.ID==TAB_GALLERY)
                        it2.active= false;
                }

//                for (auto &it:app.library)
//                {
//                    SDL_DestroyTexture(it.second);
//                }
//                app.library.clear();
//                app.libraryName.clear();
            }
            app.isOnBlock=false;
            if(it.onButton)
            {
                app.isOnBlock=true;
            }
        }
        if(it.ID==CLOSE_BUTTONGallery)
        {
            if(it.onButton)
            {
                SDL_SetRenderDrawColor(app.renderer,232,17,35,255);
                SDL_RenderFillRect(app.renderer,&it.rect);
            }
            if(it.leftClick)
            {
//                for (auto &it:app.library)
//                {
//                    SDL_DestroyTexture(it.second);
//                }
//                app.library.clear();
//                app.libraryName.clear();
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
            }
            int L=6;
            aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-L/ sqrt(2),it.rect.y+it.rect.h/2-L/sqrt(2),it.rect.x+it.rect.w/2+L/sqrt(2),it.rect.y+it.rect.h/2+L/sqrt(2),214,214,214,255);
            aalineRGBA(app.renderer,(it.rect.x+it.rect.w/2-L/ sqrt(2)),(it.rect.y+it.rect.h/2+L/sqrt(2)),(it.rect.x+it.rect.w/2+L/sqrt(2)),(it.rect.y+it.rect.h/2-L/sqrt(2)),214,214,214,255);
            aalineRGBA(app.renderer,it.rect.x+it.rect.w/2-L/ sqrt(2),it.rect.y+it.rect.h/2-L/sqrt(2)-1,it.rect.x+it.rect.w/2+L/sqrt(2),it.rect.y+it.rect.h/2+L/sqrt(2)-1,214,214,214,255);
            aalineRGBA(app.renderer,(it.rect.x+it.rect.w/2-L/ sqrt(2)),(it.rect.y+it.rect.h/2+L/sqrt(2))-1,(it.rect.x+it.rect.w/2+L/sqrt(2)),(it.rect.y+it.rect.h/2-L/sqrt(2))-1,214,214,214,255);
        }
        if(it.ID==WINDOW_BUTTONGallery)
        {
            if(it.active)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,122, 86, 199, 255);
                    SDL_RenderFillRect(app.renderer,&it.rect);
                }
                SDL_SetRenderDrawColor(app.renderer,214,214,214,255);
                SDL_Rect rectWindow={it.rect.x+it.rect.w/2-it.rect.w/10,it.rect.y+it.rect.h/2-it.rect.w/10,it.rect.w*2/10,it.rect.w*2/10};
                SDL_RenderDrawRect(app.renderer,&rectWindow);
            }
        }
        if(it.ID==MINIMIZED_BUTTONGallery)
        {
            if(it.active)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,122, 86, 199, 255);
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
        if(it.ID==uploadBackground)
        {

            roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,255,255,255,255);
            SDL_Rect night={it.rect.x+18,it.rect.y+18,124,93};
            image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*1/3,16,it.ID,true);
            if(!it.onButton)
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,217,217,217,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+1,it.rect.y+it.rect.h+1,8,217,217,217,255);
                roundedRectangleRGBA(app.renderer,it.rect.x-1,it.rect.y-1,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,217,217,217,255);
            }
            else
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,133,92,214,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+1,it.rect.y+it.rect.h+1,8,133,92,214,255);
                roundedRectangleRGBA(app.renderer,it.rect.x-1,it.rect.y-1,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,133,92,214,255);
            }
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*135/160,"Upload Background","Roman15",SDL_Color{86,89,111,255});
            if(it.leftClick)
            {
                const char *filters[] = {"*.png", "*.jpg"};
                const char *selectedFile = tinyfd_openFileDialog(
                        "Select an Image",
                        "",
                        2,
                        filters,
                        "Image Files",
                        0
                );

                if (selectedFile != NULL)
                {
                    std::string srcPath(selectedFile);

                    SDL_Texture *tex = IMG_LoadTexture(app.renderer, srcPath.c_str());

                    if (tex != nullptr)
                    {
                        SetBackground(app,tex,app.box.background);
                        SetBackground(app,app.box.background,app.box.backgroundStage);
                    }
                    SDL_DestroyTexture(tex);

                    std::string fileName = srcPath.substr(srcPath.find_last_of("\\") + 1);
                    app.box.backgroundName=std::string(fileName).substr(0,std::string(fileName).size()-4);
                    for(auto &it2:tabs)
                    {
                        if(it2.ID==TAB_GENERAL)
                            it2.active=true;
                        if(it2.ID==TAB_CODE)
                            it2.active=true;
                        if(it2.ID==TAB_GALLERY)
                            it2.active= false;
                        if(it2.ID==TAB_COSTUMES)
                        {
                            for(auto &it3:it2.buttons)
                                if(it3.ID==backgroundName)
                                {
                                    it3.text=app.box.backgroundName;
                                }
                        }
                    }

                    std::string destPath = std::string("backgroundLibrary") + "\\" + fileName;
                    CopyFileA(srcPath.c_str(), destPath.c_str(), FALSE);

                    loadPNGLibrary(app);
                }
            }

        }
        if(10000<=it.ID && it.ID<=10023 && (it.ID-10000)<=app.library.size())
        {
            roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,255,255,255,255);
            int gap=16*app.W/1350;
            SDL_Rect night={it.rect.x+gap,it.rect.y+gap,it.rect.w-2*gap,it.rect.w-4*gap};
            SDL_RenderCopy(app.renderer,app.library[it.ID-10000],NULL,&night);
            if(!it.onButton)
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,217,217,217,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+1,it.rect.y+it.rect.h+1,8,217,217,217,255);
                roundedRectangleRGBA(app.renderer,it.rect.x-1,it.rect.y-1,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,217,217,217,255);
            }
            else
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,133,92,214,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+1,it.rect.y+it.rect.h+1,8,133,92,214,255);
                roundedRectangleRGBA(app.renderer,it.rect.x-1,it.rect.y-1,it.rect.x+it.rect.w,it.rect.y+it.rect.h,8,133,92,214,255);
            }
            text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*135/160,app.libraryName[it.ID-10000],"Roman17",SDL_Color{86,89,111,255});
            if(it.leftClick)
            {
                app.box.backgroundName=app.libraryName[it.ID-10000];
                SetBackground(app,app.library[it.ID-10000],app.box.background);
                SetBackground(app,app.box.background,app.box.backgroundStage);
                for(auto &it2:tabs)
                {
                    if(it2.ID==TAB_GENERAL)
                        it2.active=true;
                    if(it2.ID==TAB_CODE)
                        it2.active=true;
                    if(it2.ID==TAB_GALLERY)
                        it2.active= false;
                    if(it2.ID==TAB_COSTUMES)
                    {
                        for(auto &it3:it2.buttons)
                            if(it3.ID==backgroundName)
                            {
                           it3.text=app.libraryName[it.ID-10000];
                            }

                    }
                }

//                for (auto &it:app.library)
//                {
//                    SDL_DestroyTexture(it.second);
//                }
//                app.library.clear();
//                app.libraryName.clear();
            }
        }
    }



}
SDL_Texture* createRedTintedTexture(SDL_Renderer* renderer, SDL_Texture* texture) {
    // 1. اطلاعات تکسچر
    int w, h;
    Uint32 format;
    SDL_QueryTexture(texture, &format, NULL, &w, &h);

    // 2. یه سرفیس از تکسچر بساز با دسترسی مستقیم به پیکسل‌ها
    SDL_Texture* readable = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
                                              SDL_TEXTUREACCESS_STREAMING, w, h);
    if (!readable) return nullptr;

    // 3. پیکسل‌های اصلی رو بخون از طریق render target
    SDL_Texture* oldTarget = SDL_GetRenderTarget(renderer);
    SDL_Texture* tempTarget = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA32,
                                                SDL_TEXTUREACCESS_TARGET, w, h);
    if (!tempTarget) {
        SDL_DestroyTexture(readable);
        return nullptr;
    }

    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_NONE);
    SDL_SetRenderTarget(renderer, tempTarget);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

    // 4. بخون توی سرفیس
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, w, h, 32, SDL_PIXELFORMAT_RGBA32);
    if (!surface) {
        SDL_SetRenderTarget(renderer, oldTarget);
        SDL_DestroyTexture(tempTarget);
        SDL_DestroyTexture(readable);
        return nullptr;
    }

    SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_RGBA32,
                         surface->pixels, surface->pitch);
    SDL_SetRenderTarget(renderer, oldTarget);
    SDL_DestroyTexture(tempTarget);
    SDL_DestroyTexture(readable);

    // 5. پردازش پیکسل‌ها — دقیقاً مثل تابع خودت
    SDL_LockSurface(surface);
    Uint32* pixels = (Uint32*)surface->pixels;
    int pixelCount = w * h;

    for (int i = 0; i < pixelCount; i++) {
        Uint8 r, g, b, a;
        SDL_GetRGBA(pixels[i], surface->format, &r, &g, &b, &a);

        if (a == 0) continue;

        float h, s, v;
        rgbToHsv(r, g, b, h, s, v);

        // سفید و نزدیک سفید رو رد کن (saturation خیلی کم)
        if (s < 0.1f) continue;

        // Hue رو ست کن روی قرمز (0 درجه) — بقیه مقادیر دست نخورده
        h = 0.0f;

        Uint8 nr, ng, nb;
        hsvToRgb(h, s, v, nr, ng, nb);

        pixels[i] = SDL_MapRGBA(surface->format, nr, ng, nb, a);
    }

    SDL_UnlockSurface(surface);

    // 6. تکسچر نهایی
    SDL_Texture* result = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (result) {
        SDL_SetTextureBlendMode(result, SDL_BLENDMODE_BLEND);
    }

    return result;
}
void SetBackground(AppState &app, SDL_Texture* t1, SDL_Texture* t2)
{
    int t1W, t1H, t2W, t2H;
    SDL_QueryTexture(t1, NULL, NULL, &t1W, &t1H);
    SDL_QueryTexture(t2, NULL, NULL, &t2W, &t2H);

    float scaleW = (float)t1W / t2W;
    float scaleH = (float)t1H / t2H;
    float scale  = (scaleW > scaleH) ? scaleH : scaleW;

    int cropW = (int)(t2W * scale);
    int cropH = (int)(t2H * scale);
    int cropX = (t1W - cropW) / 2;
    int cropY = (t1H - cropH) / 2;

    SDL_Rect srcRect = { cropX, cropY, cropW, cropH };

    SDL_SetRenderTarget(app.renderer, t2);
    SDL_SetRenderDrawColor(app.renderer,0,0,0,0);
    SDL_RenderClear(app.renderer);
    SDL_RenderCopy(app.renderer, t1, &srcRect, NULL);
    SDL_SetRenderTarget(app.renderer, NULL);
}
void loadPNGLibrary(AppState &app)
{

    for (auto &it:app.library)
    {
        SDL_DestroyTexture(it.second);
    }
    app.library.clear();
    app.libraryName.clear();

    std::string searchPath = "backgroundLibrary\\*.png";

    WIN32_FIND_DATAA findData;

    HANDLE hFind = FindFirstFileA(searchPath.c_str(), &findData);
    if(hFind==INVALID_HANDLE_VALUE)
        return;
    app.libraryName[1]=std::string(findData.cFileName).substr(0,std::string(findData.cFileName).size()-4);
    app.library[1]= IMG_LoadTexture(app.renderer,("backgroundLibrary\\"+app.libraryName[1]+".png").c_str());
    for(int i=2;FindNextFileA(hFind, &findData);i++)
    {
        if(i>=24)
        {
            SDL_MessageBoxButtonData buttons[] = {
                    {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "OK"}
            };
            SDL_MessageBoxData msgBox = {
                    SDL_MESSAGEBOX_WARNING,
                    app.window,
                    "Background Library",
                    "Background library is full. \n Remove some backgrounds",
                    1,
                    buttons,
                    NULL
            };
            int buttonId = -1;
            SDL_ShowMessageBox(&msgBox, &buttonId);
            if(buttonId==0)
                return;

            return;
        }
        app.libraryName[i]=std::string(findData.cFileName).substr(0,std::string(findData.cFileName).size()-4);
        app.library[i]= IMG_LoadTexture(app.renderer,("backgroundLibrary\\"+app.libraryName[i]+".png").c_str());
        if(!app.library[i])
        {
            app.endProgram=true;
            std::cout<<"Error in load Library"<<std::endl;
            return;
        }

    }
    FindClose(hFind);
}
bool LibraryChanged(AppState &app)
{
    if (WaitForSingleObject(app.hChange, 0) == WAIT_OBJECT_0)
    {
        FindNextChangeNotification(app.hChange);
        return true;
    }
    return false;
}




//// Golab function

void RenderGeneralTap(std::vector<ButtonRect> &buttons, AppState &app, ThemeGeneralTab &color,MouseState &mouse,std::vector<AllTabButtons> &tabs)

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


    }

    for(auto &it:buttons)
    {
        int rad=7;
        if( app.fileMenu)
        {
            if(it.ID==fileMenu)
            {
                SDL_RenderSetClipRect(app.renderer, &it.rect);
                roundedBoxRGBA(app.renderer,it.rect.x,0,it.rect.x+it.rect.w,it.rect.y+it.rect.h,9,color.topBar.r,color.topBar.g,color.topBar.b,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,0,it.rect.x+it.rect.w,it.rect.y+it.rect.h,9,color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,255);
                SDL_RenderSetClipRect(app.renderer, NULL);
                aalineRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y,color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,255);
                if(mouse.leftDown && !it.onButton)
                    app.fileMenu=false;
            }
            if(it.ID==fileNew)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,255);
                    SDL_RenderFillRect(app.renderer,&it.rect);
                }
                text(app,it.rect.x+it.rect.w*1/15,it.rect.y+it.rect.h*3/8,"New Project","Bold13",color.white,true);
                if(it.leftClick) {
                    SDL_MessageBoxButtonData buttons[] = {
                            {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "Cancel"},
                            {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Don't Save"},
                            {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 2, "Save"}
                    };
                    SDL_MessageBoxData msgBox = {
                            SDL_MESSAGEBOX_WARNING,
                            app.window,
                            "New Project",
                            "Do you want to save the current project?",
                            3,
                            buttons,
                            NULL
                    };
                    int buttonId = -1;
                    SDL_ShowMessageBox(&msgBox, &buttonId);
                    if (buttonId == 1)
                    {
                        app.block.clear();
                        app.allblock.clear();
                        app.box.x=0;
                        app.box.y=0;
                        app.box.scale=100;
                        app.box.angle=90;
                        for(auto &it1:tabs)
                        {
                            if(it1.ID==TAB_COSTUMES)
                            {
                                for(auto &it2:it1.buttons)
                                {
                                    if(it2.ID==showSpace)
                                    {
                                        SDL_SetRenderTarget(app.renderer,app.box.t);
                                        SDL_SetRenderDrawColor(app.renderer,0,0,0,0);
                                        SDL_RenderClear(app.renderer);
                                        image(app,it2.rect.w/2,it2.rect.h/2, 1, gorbaStandard, true);
                                        SDL_SetRenderTarget(app.renderer,NULL);
                                    }
                                    if(it2.ID==nameCostumeTextInput)
                                    {
                                        it2.text="costume1";
                                    }
                                    if(it2.ID==xImageTextInput)
                                    {
                                        it2.text="0";
                                    }
                                    if(it2.ID==yImageTextInput)
                                    {
                                        it2.text="0";
                                    }
                                    if(it2.ID==sizeImageTextInput)
                                    {
                                        it2.text="100";
                                    }
                                }

                            }
                            if(it1.ID==TAB_GENERAL)
                            {
                                for(auto &it2:it1.buttons)
                                {
                                    if(it2.ID==xSpriteTextInput)
                                    {
                                        it2.text="0";
                                    }
                                    if(it2.ID==ySpriteTextInput)
                                    {
                                        it2.text="0";
                                    }
                                    if(it2.ID==sizeSpriteTextInput)
                                    {
                                        it2.text="100";
                                    }
                                    if(it2.ID==directionSpriteTextInput)
                                    {
                                        it2.text="90";
                                    }
                                    app.box.isShowing=true;
                                }
                            }
                        }
                        clearPenTexture(app);
                        SDL_SetRenderTarget(app.renderer,app.box.background);
                        SDL_SetRenderDrawColor(app.renderer,0,0,0,0);
                        SDL_RenderClear(app.renderer);
                        SDL_SetRenderTarget(app.renderer,NULL);
                        SetBackground(app,app.box.background,app.box.backgroundStage);
                    }
                    if(buttonId==2)
                    {
                        SaveProject(app);
                    }

                }


            }
            if(it.ID==fileSave)
            {
                if(it.onButton)
                {
                    SDL_SetRenderDrawColor(app.renderer,color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,255);
                    SDL_RenderFillRect(app.renderer,&it.rect);
                }
                if(it.leftClick)
                {
                    SaveProject(app);
                }
                text(app,it.rect.x+it.rect.w*1/15,it.rect.y+it.rect.h*3/8,"Save Project","Bold13",color.white,true);
            }
            if(it.ID==fileLoad)
            {
                if(it.onButton)
                {

                    SDL_RenderSetClipRect(app.renderer, &it.rect);
                    roundedBoxRGBA(app.renderer,it.rect.x,0,it.rect.x+it.rect.w,it.rect.y+it.rect.h,9,color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,255);
                    SDL_RenderSetClipRect(app.renderer, NULL);

                }
                if(it.leftClick)
                {
                    SDL_MessageBoxButtonData buttons[] = {
                            {SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 0, "Cancel"},
                            {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "Don't Save"},
                            {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 2, "Save"}
                    };
                    SDL_MessageBoxData msgBox = {
                            SDL_MESSAGEBOX_WARNING,
                            app.window,
                            "Load Project",
                            "Do you want to save the current project?",
                            3,
                            buttons,
                            NULL
                    };
                    int buttonId = -1;
                    SDL_ShowMessageBox(&msgBox, &buttonId);
                    if(buttonId==2)
                    {
                        SaveProject(app);
                    }
                    if(buttonId==1)
                    {
                        LoadProject(app);
                        clearPenTexture(app);
                        SetBackground(app,app.box.background,app.box.backgroundStage);
                        for(auto &it2:tabs)
                        {
                            if(it2.ID==TAB_COSTUMES)
                            {
                                for(auto &it3:it2.buttons)
                                    if(it3.ID==backgroundName)
                                    {
                                        it3.text=app.box.backgroundName;
                                    }
                            }
                        }
                    }
                }
                text(app,it.rect.x+it.rect.w*1/15,it.rect.y+it.rect.h*3/8,"Load Project","Bold13",color.white,true);
            }

        }
        if(it.ID==FILE_BUTTON && it.leftClick)
        {
            if(!app.fileMenu)
                app.fileMenu=true;
        }
        if(it.ID == stageBackground)
        {
            roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h+100,15*app.W/1350,255,255,255,255);
            roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h+100,15,185,193,206,255);
            aalineRGBA(app.renderer,it.rect.x,it.rect.y+app.H*40/609,it.rect.x+it.rect.w,it.rect.y+app.H*40/609,185,193,206,255);
            text(app,it.rect.x+it.rect.w/2,it.rect.y+app.H*40/609/2,"Stage","Medium10",SDL_Color{87,84,117,255});
            if(app.box.background!=NULL)
            {
                int w, h;
                SDL_QueryTexture(app.box.background, NULL, NULL, &w, &h);
                SDL_Rect dest={ it.rect.x+it.rect.w/2-w/18,it.rect.y+it.rect.h*10/32 -h/18,w/9,h/9};
                SDL_RenderCopy(app.renderer, app.box.background, NULL, &dest);
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h*15/32,"background","Roman10",SDL_Color{87,84,117,255});
            }


        }
        if(it.ID == spriteState)
        {
            roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15*app.W/1350,255,255,255,255);
            roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,185,193,206,255);
         //   aalineRGBA(app.renderer,it.rect.x,it.rect.y+app.H*90/609,it.rect.x+it.rect.w,it.rect.y+app.H*90/609,185,193,206,255);
        }
        if(4041<=it.ID && it.ID<=4045 && it.active)
        {
            if(!it.onButton)
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,218,218,218,255);
            }
            else
            {
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,15,133,92,214,255);
            }
            if(it.ID!=nameSpriteTextInput)
                text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,it.text,"Roman10",SDL_Color{87, 94, 117,255});
            else
                 text(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2+2,it.text,"Medium10",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==nameSpriteTextInput)
        {
            text(app,it.rect.x-it.rect.w/6,it.rect.y+it.rect.h/2+2,"Sprite","Medium10",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==xSpriteTextInput)
        {
            text(app,it.rect.x-it.rect.w/5,it.rect.y+it.rect.h/2+1,"x","Roman10",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==ySpriteTextInput)
        {
            text(app,it.rect.x-it.rect.w/5,it.rect.y+it.rect.h/2+1,"y","Roman10",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==sizeSpriteTextInput)
        {
            text(app,it.rect.x-it.rect.w/4,it.rect.y+it.rect.h/2+1,"Size","Roman10",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==directionSpriteTextInput)
        {
            text(app,it.rect.x-it.rect.w*5/12,it.rect.y+it.rect.h/2+2,"Direction","Roman10",SDL_Color{87, 94, 117,255});
        }
        if(it.ID==showButton)
        {
            text(app,it.rect.x-it.rect.w/2,it.rect.y+it.rect.h/2+1,"Show","Roman10",SDL_Color{87, 94, 117,255});
         if(it.leftClick)
             app.box.isShowing=true;
         SDL_Rect rectShow={it.rect.x-1,it.rect.y-1,it.rect.w+1,it.rect.h+2};
            if(app.box.isShowing)
            {
                SDL_RenderSetClipRect(app.renderer,&rectShow);
                roundedBoxRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+100,it.rect.y+it.rect.h,rad,237,231,249,255);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+100,it.rect.y+it.rect.h,rad,113,78,182,255);
                image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1,showButtonActive,true);
                SDL_RenderSetClipRect(app.renderer,NULL);
            }
            else
            {
                SDL_RenderSetClipRect(app.renderer,&rectShow);
                roundedRectangleRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x+it.rect.w+100,it.rect.y+it.rect.h,rad,218,218,218,255);
                image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1,showButton,true);
                SDL_RenderSetClipRect(app.renderer,NULL);
            }
        }
        if(it.ID==hideButton)
        {
            if(it.leftClick)
                app.box.isShowing=false;

            SDL_Rect rectHide={it.rect.x,it.rect.y-1,it.rect.w+2,it.rect.h+2};
            if(!app.box.isShowing)
            {
                SDL_RenderSetClipRect(app.renderer,&rectHide);
                roundedBoxRGBA(app.renderer,it.rect.x-100,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,rad,237,231,249,255);
                roundedRectangleRGBA(app.renderer,it.rect.x-100,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,rad,113,78,182,255);
                image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1,hideButtonActive,true);
                SDL_RenderSetClipRect(app.renderer,NULL);
            }
            else
            {
                SDL_RenderSetClipRect(app.renderer,&rectHide);
                roundedRectangleRGBA(app.renderer,it.rect.x-100,it.rect.y,it.rect.x+it.rect.w,it.rect.y+it.rect.h,rad,218,218,218,255);
                image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1,hideButton,true);
                SDL_RenderSetClipRect(app.renderer,NULL);
            }
            aalineRGBA(app.renderer,it.rect.x,it.rect.y,it.rect.x,it.rect.y+it.rect.h,113,78,182,255);

        }
        if(it.ID==backgroundGallery)
        {
            filledCircleRGBA(app.renderer,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,it.rect.h/2+4,212,198,241,255);
            filledCircleRGBA(app.renderer,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,it.rect.h/2,133,92,214,255);
            image(app,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,1,it.ID,true);
            aacircleRGBA(app.renderer,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,it.rect.h/2,212,198,241,255);
            aacircleRGBA(app.renderer,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,it.rect.h/2+1,212,198,241,255);
            aacircleRGBA(app.renderer,it.rect.x+it.rect.w/2,it.rect.y+it.rect.h/2,it.rect.h/2+4,212,198,241,255);
            if(it.leftClick)
            {
                SDL_RenderClear(app.renderer);
                for(auto &it2:tabs)
                {
                    it2.active=false;
                    if(it2.ID == TAB_GALLERY)
                        it2.active=true;

                }
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
    SDL_Rect fileRect;
    for(auto & it : buttons)
    {
        if(it.ID == FILE_BUTTON)
        {
            fileRect=it.rect;
            barHeight = it.rect.h;
            break;

        }
    }




    SDL_Rect topBar ={0,0,app.W,barHeight};
    SDL_SetRenderDrawColor(app.renderer,color.topBar.r,color.topBar.g,color.topBar.b,color.topBar.a);
    SDL_RenderFillRect(app.renderer,&topBar);
    //صفحه استیج
    SDL_SetRenderDrawColor(app.renderer,255,255,255,255);
    roundedBoxRGBA(app.renderer,app.stageRect.x,app.stageRect.y,app.stageRect.x+app.stageRect.w,app.stageRect.h+app.stageRect.y,15*app.W/1365,255,255,255,255);
    SDL_RenderCopy(app.renderer,app.box.backgroundStage, NULL, &app.stageRect);
    roundedRectangleRGBA(app.renderer,app.stageRect.x,app.stageRect.y,app.stageRect.x+app.stageRect.w,app.stageRect.h+app.stageRect.y,15*app.W/1365,185,193,206,255);


    // ایکون ها

    for(auto& it :buttons) {
        if (it.ID == SETTING_BUTTON) {
            if (it.onButton) {
                SDL_SetRenderDrawColor(app.renderer, color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,
                                       255);
                SDL_RenderFillRect(app.renderer, &it.rect);

            }
            std::string u = "Settings";
            SDL_Rect set = {it.rect.x+it.rect.w*10/48-10, it.rect.y+it.rect.h/2-10, 20, 20};
            SDL_Rect flesh = {it.rect.x+it.rect.w*27/32-4, it.rect.y+it.rect.h*27/50-2, 8, 5};
            SDL_RenderCopy(app.renderer, buttonTextures.setting, nullptr, &set);
            SDL_RenderCopy(app.renderer, buttonTextures.flesh, nullptr, &flesh);
            text(app, it.rect.x+it.rect.w*13/24, it.rect.y+it.rect.h*17/32, u, "Bold12", color.white);

        }
        else if (it.ID == EDIT_BUTTON) {
            if (it.onButton) {
                SDL_SetRenderDrawColor(app.renderer, color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,
                                       255);
                SDL_RenderFillRect(app.renderer, &it.rect);

            }
            std::string u = "Edit";
            SDL_Rect edit = {it.rect.x+it.rect.w*3/12-10, it.rect.y+it.rect.h*26/50-10, 21, 20};
            SDL_Rect flesh = {it.rect.x+it.rect.w*9/12-4, it.rect.y+it.rect.h*28/50-2, 8, 5};
            SDL_RenderCopy(app.renderer, buttonTextures.edit, nullptr, &edit);
            SDL_RenderCopy(app.renderer, buttonTextures.flesh, nullptr, &flesh);
            text(app, it.rect.x+it.rect.w*6/12, it.rect.y+it.rect.h*17/32, u, "Bold12", color.white);
        }
        else if (it.ID == FILE_BUTTON) {
            if (it.onButton || app.fileMenu) {
                SDL_SetRenderDrawColor(app.renderer, color.topBarhaber.r, color.topBarhaber.g, color.topBarhaber.b,
                                       255);
                SDL_RenderFillRect(app.renderer, &it.rect);

            }
            std::string u = "File";
            SDL_Rect file = {it.rect.x+it.rect.w*6/24-10, it.rect.y+it.rect.h*27/50-10, 21, 20};
            SDL_Rect flesh = {it.rect.x+it.rect.w*10/12-4, it.rect.y+it.rect.h*28/50-2, 8, 5};
            SDL_RenderCopy(app.renderer, buttonTextures.file, nullptr, &file);
            SDL_RenderCopy(app.renderer, buttonTextures.flesh, nullptr, &flesh);
            text(app, it.rect.x+it.rect.w*7/12, it.rect.y+it.rect.h*17/32, u, "Bold12", color.white);


        }
        else if (it.ID == CODE_BUTTON) {
            roundedRectangleRGBA(app.renderer, 0, it.rect.y, it.rect.w, it.rect.y + 60, 10, 185, 193, 209, 255);
            roundedBoxRGBA(app.renderer, 1, it.rect.y + 1, it.rect.w -1, it.rect.y + 60, 10, 217, 227, 242, 255);
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, 1, it.rect.y + 1, it.rect.w - 1, it.rect.y + 60, 10, 230, 240, 255, 255);

            }
            std::string u = "Code";
            SDL_Rect code = {it.rect.x+it.rect.w*3/10-11, it.rect.y+it.rect.h/2-11, 22, 22};
            SDL_RenderCopy(app.renderer, buttonTextures.code, nullptr, &code);
            text(app,it.rect.x+it.rect.w*6/10, it.rect.y+it.rect.h/2 , u, "Medium12", {123, 131, 152, 255});
            if(it.leftClick&& !app.fileMenu)
            {
                for(auto &it:tabs)
                {
                    if(it.ID==TAB_CODE)
                    {
                        it.active=true;
                    }
                    else if(it.ID!=TAB_GENERAL)
                    {
                        it.active=false;
                    }
                }
            }

        }
        else if (it.ID == COSTUMES_BUTTON) {
            roundedRectangleRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.y + 60, 10, 185, 193,
                                 209, 255);
            roundedBoxRGBA(app.renderer, it.rect.x+1, it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10, 217,
                           227, 242, 255);
            if (it.onButton) {
                roundedBoxRGBA(app.renderer,  + it.rect.x, it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10,
                               230, 240, 255, 255);

            }
            std::string u = "Costumes";
            SDL_Rect costom = {it.rect.x+it.rect.w*2/10-15, it.rect.y+it.rect.h/2-11, 22, 22};
            SDL_RenderCopy(app.renderer, buttonTextures.custumes, nullptr, &costom);
            text(app,it.rect.x+it.rect.w*6/10, it.rect.y+it.rect.h/2 , u, "Medium12", {123, 131, 152, 255});


            if(it.leftClick && !app.fileMenu)
            {
                for(auto &it:tabs)
                {
                    if(it.ID==TAB_COSTUMES)
                    {
                        it.active=true;
                    }
                    else if(it.ID!=TAB_GENERAL)
                    {
                        it.active=false;
                    }
                }
            }

        }
        else if (it.ID == SOUNDS_BUTTON) {
            roundedRectangleRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.y + 60, 10, 185, 193,209, 255);
            roundedBoxRGBA(app.renderer, 1 + it.rect.x , it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10, 217,227, 242, 255);
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, 1 + it.rect.x, it.rect.y + 1, it.rect.w - 1+it.rect.x, it.rect.y + 60, 10,230, 240, 255, 255);

            }
            std::string u = "Sound";
            SDL_Rect sound = {it.rect.x+it.rect.w*5/20-11, it.rect.y+it.rect.h/2-12, 22, 22};
            SDL_RenderCopy(app.renderer, buttonTextures.sounds, nullptr, &sound);
            text(app,it.rect.x+it.rect.w*6/10, it.rect.y+it.rect.h/2 , u, "Medium12", {123, 131, 152, 255});


            if(it.leftClick && !app.fileMenu)
            {
                for(auto &it:tabs)
                {
                    if(it.ID==TAB_SOUNDS)
                    {
                        it.active=true;
                    }
                    else if(it.ID!=TAB_GENERAL)
                    {
                        it.active=false;
                    }
                }
            }

        }
        else if (it.ID == GO_BUTTON) {
            if (it.onButton)
            {
                roundedBoxRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.h+it.rect.y, 3, 216, 218, 249, 255);
            }
            if(it.leftClick)
            {
                go= true;
            }
            SDL_Rect u={it.rect.x+4,it.rect.y+4,20,20};
            SDL_RenderCopy(app.renderer, buttonTextures.Go, nullptr,&u );
        }
        else if (it.ID == STOP_BUTTON){
            if (it.onButton) {
                roundedBoxRGBA(app.renderer, it.rect.x, it.rect.y, it.rect.w+it.rect.x, it.rect.h+it.rect.y, 3, 216, 218, 249, 255);
            }
            if(it.leftClick)
            {
                stop= true;
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
    SDL_RenderSetClipRect(app.renderer, &app.stageRect);

    int X=-box.w/2+app.stageRect.x+app.stageRect.w/2+box.x;
    int Y=-box.h/2+app.stageRect.y+app.stageRect.h/2-box.y;
    SDL_Rect u={X,Y,int(box.w),int(box.h)};
    SDL_Texture* catTexToRender = app.box.t;




    if (app.colorEffect != 0 && app.boxOriginalSurface) {
        if (app.colorEffect != app.lastAppliedColorEffect) {
            if (app.boxEffectTexture) {
                SDL_DestroyTexture(app.boxEffectTexture);
                app.boxEffectTexture = nullptr;
            }
            app.boxEffectTexture = createHueShiftedTexture(app.renderer,app.boxOriginalSurface,app.colorEffect);
            app.lastAppliedColorEffect = app.colorEffect;
        }
        if (app.boxEffectTexture) {
            catTexToRender = app.boxEffectTexture;
            u.w = int(box.w/2/250*213) ;
            u.h = int(box.h/2/250*215) ;
            u.x = X + (int(box.w) - u.w) / 2;
            u.y = Y + (int(box.h) - u.h) / 2;
        }
    } else if (app.colorEffect == 0) {
        if (app.boxEffectTexture) {
            SDL_DestroyTexture(app.boxEffectTexture);
            app.boxEffectTexture = nullptr;
            app.lastAppliedColorEffect = -999;

        }

        SDL_SetTextureColorMod(app.box.t, 255, 255, 255);
    }
    if (app.brightnessEffect != 0 && app.boxOriginalSurface) {
        if (app.brightnessEffect != app.lastAppliedBrightnessEffect) {
            if (app.boxBrightnessTexture) {
                SDL_DestroyTexture(app.boxBrightnessTexture);
                app.boxBrightnessTexture = nullptr;
            }
            app.boxBrightnessTexture = createBrightnessTexture(app.renderer,app.boxOriginalSurface,app.brightnessEffect);
            app.lastAppliedBrightnessEffect = app.brightnessEffect;
        }
        if (app.boxBrightnessTexture) {
            catTexToRender = app.boxBrightnessTexture;
            u.w = int(box.w / 2 / 250 * 213);
            u.h = int(box.h / 2 / 250 * 215);
            u.x = X + (int(box.w) - u.w) / 2;
            u.y = Y + (int(box.h) - u.h) / 2;
        }
    } else if (app.brightnessEffect == 0) {
        if (app.boxBrightnessTexture) {
            SDL_DestroyTexture(app.boxBrightnessTexture);
            app.boxBrightnessTexture = nullptr;
            app.lastAppliedBrightnessEffect = -999;
        }
    }
    if (app.ghostEffect != 0 && app.boxOriginalSurface) {
        if (app.ghostEffect != app.lastAppliedghostEffect) {
            if (app.boxghostTexture) {
                SDL_DestroyTexture(app.boxghostTexture);
                app.boxghostTexture = nullptr;
            }
            app.boxghostTexture = createGhostTexture(app.renderer,app.boxOriginalSurface,app.ghostEffect);
            app.lastAppliedghostEffect = app.ghostEffect;
        }
        if (app.boxghostTexture) {
            catTexToRender = app.boxghostTexture;
            u.w = int(box.w / 2 / 250 * 208);
            u.h = int(box.h / 2 / 250 * 215);
            u.x = X + (int(box.w) - u.w) / 2;
            u.y = Y + (int(box.h) - u.h) / 2;
        }
    } else if (app.ghostEffect == 0) {
        if (app.boxghostTexture) {
            SDL_DestroyTexture(app.boxghostTexture);
            app.boxghostTexture = nullptr;
            app.lastAppliedghostEffect = -999;
        }
    }
    SDL_RenderCopy(app.renderer,app.penTexture,nullptr,&app.stageRect);
    SDL_RenderCopyEx(app.renderer, catTexToRender, nullptr, &u, box.angle-90, nullptr, SDL_FLIP_NONE);
    SDL_RenderSetClipRect(app.renderer, NULL);
    inverseRoundedBoxRGBA(app.renderer,app.stageRect.x-1,app.stageRect.y-1,app.stageRect.x+app.stageRect.w+1,app.stageRect.y+app.stageRect.h+1,15*app.W/1365,230,240,255,255);

////
    if(app.isSaying){
        float deg=box.angle-90;

        SDL_Rect rect;
        rect.w=app.W*85/1503;
        rect.h=app.H*37/609;
        rect.x=X+115*box.w/200;
        if(rect.x+rect.w>app.stageRect.x+app.stageRect.w)
            rect.x=app.stageRect.x+app.stageRect.w-rect.w;
        else if(rect.x<app.stageRect.x)
            rect.x=app.stageRect.x;

        rect.y=Y+22*app.stageRect.h/105-rect.h;
        if(rect.y<app.stageRect.y)
            rect.y=app.stageRect.y;
        else if(rect.y+rect.h>app.stageRect.y+app.stageRect.h)
            rect.y=app.stageRect.y+app.stageRect.h-rect.h;

        SDL_RenderCopyEx(app.renderer,app.saytexture, nullptr,&rect,0, nullptr,SDL_FLIP_NONE);
        text(app,rect.x+rect.w/2,rect.y+rect.h*43/100,app.say,"Medium12",{93,100,122,255},false);

    }


    if(app.isThinking){

        SDL_Rect rect;
        rect.w=app.W*85/1503;
        rect.h=app.H*45/609;
        rect.x=X+115*box.w/200;
        if(rect.x+rect.w>app.stageRect.x+app.stageRect.w)
            rect.x=app.stageRect.x+app.stageRect.w-rect.w;
        else if(rect.x<app.stageRect.x)
            rect.x=app.stageRect.x;

        rect.y=Y+22*app.stageRect.h/105-rect.h;
        if(rect.y<app.stageRect.y)
            rect.y=app.stageRect.y;
        else if(rect.y+rect.h>app.stageRect.y+app.stageRect.h)
            rect.y=app.stageRect.y+app.stageRect.h-rect.h;

        SDL_RenderCopyEx(app.renderer,app.thinktexture, nullptr,&rect,0, nullptr,SDL_FLIP_NONE);
        text(app,rect.x+rect.w/2,rect.y+rect.h*43/100,app.say,"Medium12",{93,100,122,255},false);

    }

};
void Engine(AppState &app,std::vector<AllTabButtons> &tabs,MouseState &mouse,KeyboardButton &key) {
    if (go) {
        go = false;
        if (!app.block.empty() && app.block[0].ID == whenGreenFlagClicked) {
            app.engineRunning = true;

        }

    }
    if(stop){
        app.engineRunning=false;
        stop= false;
    }
    if(!app.engineRunning){
        if(app.isWaiting){
            Uint32 t= SDL_GetTicks()-app.waitStartTime;
            double T=app.waitDuration-t/1000.0;
            app.waitRemaining=(T>0)? T:0;
        }
        return;
    }

    if (app.engineFinished) {
        app.engineCurrentIndex = 0;
        app.engineFinished = false;
        app.isWaiting = false;
        app.isSaying=false;
        app.isThinking=false;
        app.waitRemaining = 0;
        app.isRepeating = false;
        app.repeatCounter = 0;
        app.repeatInnerIndex = 0;
    }
    if(app.isWaiting&& app.waitRemaining>0){
        app.waitDuration=app.waitRemaining;
        app.waitStartTime=SDL_GetTicks();
        app.waitRemaining=0;
    }

    if (app.isWaiting) {
        Uint32 t = SDL_GetTicks() - app.waitStartTime;
        if (t>= (Uint32)(app.waitDuration * 1000)) {
            app.isWaiting = false;
            app.isSaying=false;
            app.isThinking=false;
            app.waitRemaining = 0;
            if (app.isRepeating) {
                app.repeatInnerIndex++;
            } else {
                app.engineCurrentIndex++;
            }
        } else {
            return;
        }
    }
    app.cycle++;
    while(true){
        if(app.isRepeating){
            int r=app.repeatBlockIndex;
            auto &innerBlocks=app.block[r].child;
            while(app.repeatInnerIndex<innerBlocks.size()){
                auto & b =innerBlocks[app.repeatInnerIndex];
                if(b.ID==waitSecondes||b.ID==sayForSeconds||b.ID==thinkForSeconds){
                    app.isWaiting = true;
                    app.waitDuration = safeStod(b.p2,1);
                    app.waitStartTime = SDL_GetTicks();
                    app.waitRemaining = 0;
                    int line;
                    line=r+app.repeatInnerIndex;
                    Block x;
                    x.ID=b.ID;x.p1=b.p1;x.p2=b.p2;x.color=b.color;
                    executeBlock(app,x,mouse,line,tabs);

                    return;
                }
                int line;
                line=r+app.repeatInnerIndex;
                Block x;
                x.ID=b.ID;x.p1=b.p1;x.p2=b.p2;x.color=b.color;
                executeBlock(app,x,mouse,line,tabs);
                app.repeatInnerIndex++;
            }
            app.repeatCounter++;
            if(app.repeatCounter<app.repeatTotal){app.repeatInnerIndex=0;
                return;
            }
            else{
                app.isRepeating = false;
                app.repeatCounter = 0;
                app.repeatInnerIndex = 0;
                app.engineCurrentIndex = app.repeatBlockIndex + 1;
            }
            continue;
        }
        if (app.engineCurrentIndex >= (int)app.block.size()) {
            app.engineRunning = false;
            app.engineFinished = true;
            return;
        }
        Block &current = app.block[app.engineCurrentIndex];


        if (current.ID == whenGreenFlagClicked) {
            executeBlock(app, current,mouse,  app.engineCurrentIndex,tabs);
            app.engineCurrentIndex++;

            continue;
        }


        if (current.ID == waitSecondes) {
            app.isWaiting = true;
            app.waitDuration = safeStod(current.p1,10);
            app.waitStartTime = SDL_GetTicks();
            app.waitRemaining = 0;
            executeBlock(app, current,mouse,  app.engineCurrentIndex,tabs);
            return;
        }
        if (current.ID==sayForSeconds||current.ID==thinkForSeconds) {
            app.isWaiting = true;
            app.waitDuration = safeStod(current.p2,2);
            app.waitStartTime = SDL_GetTicks();
            app.waitRemaining = 0;
            executeBlock(app, current,mouse,  app.engineCurrentIndex,tabs);

            return;
        }


        if (current.ID == repeat) {
            app.isRepeating = true;
            app.repeatBlockIndex = app.engineCurrentIndex;
            app.repeatTotal = safeStod(current.p1,1);
            app.repeatCounter = 0;
            app.repeatInnerIndex = 0;
            executeBlock(app, current,mouse,  app.engineCurrentIndex,tabs);
            continue;
        }


        executeBlock(app, current,mouse,  app.engineCurrentIndex,tabs);
        app.engineCurrentIndex++;
    }
}
double safeStod(const std::string &s, double defaultVal )
{
    if(s.empty()) return defaultVal;
    try {
        return std::stod(s);
    } catch(...) {
        return defaultVal;
    }
}
void executeBlock(AppState& app, Block & block,MouseState &mouse,int line,std::vector<AllTabButtons> &tabs)
{
    switch(block.ID){
        case move:{
            int h=app.stageRect.h;
            int w=app.stageRect.w;
            float x0=app.box.x;
            float y0=app.box.y;
            app.box.x+= safeStod(block.p1,10)*sin(app.box.angle*M_PI/180.0);
            app.box.y+=safeStod(block.p1,10)*cos(app.box.angle*M_PI/180.0);

            if(app.box.x<=-w/2)
                app.box.x=-w/2;
            else if(app.box.x>=w/2)
                app.box.x=w/2;
            if(app.box.y<=-h/2)
                app.box.y=-h/2;
            else if(app.box.y>=h/2)
                app.box.y=h/2;
            pening(app.isPenDown,app,x0,y0);
            std::string inf="[x: "+std::to_string(int(x0))+"->"+std::to_string(int(app.box.x))+"] [y:"+std::to_string(int(y0))+"->"+std::to_string(int(app.box.y))+"]";
            LogEvent(app,line,"MOVE",inf);
            break;

        }
        case turnRDegrees:
        {   double angle=app.box.angle;
            app.box.angle+=safeStod(block.p1,15);
            std::string inf="[theta"+std::to_string(int(angle))+"->"+std::to_string(int(app.box.angle))+"]";
            LogEvent(app,line,"TURN_R",inf);
            break;
        }
        case turnLDegrees:
        {   double angle=app.box.angle;
            app.box.angle-=safeStod(block.p1,15);
            std::string inf="[theta"+std::to_string(int(angle))+"->"+std::to_string(int(app.box.angle))+"]";
            LogEvent(app,line,"TURN_L",inf);
            break;
        }
        case goToXY:
        {
            int x0=app.box.x;
            int y0=app.box.y;
            int h=app.stageRect.h;
            int w=app.stageRect.w;
            float gx = safeStod(block.p1, 0.0);
            float gy = safeStod(block.p2, 0.0);
            app.box.x = gx;
            app.box.y = gy;
            if(app.box.x<=-w/2)
                app.box.x=-w/2;
            else if(app.box.x>=w/2)
                app.box.x=w/2;
            if(app.box.y<=-h/2)
                app.box.y=-h/2;
            else if(app.box.y>=h/2)
                app.box.y=h/2;
            pening(app.isPenDown,app,x0,y0);
            std::string inf="[x"+std::to_string(int(x0))+"->"+std::to_string(int(app.box.x))+"] [y:"+std::to_string(int(y0))+"->"+std::to_string(int(app.box.y))+"]";
            LogEvent(app,line,"GOTO_XY",inf);
            break;
        }
        case changeXBy:{
            int x0=app.box.x;
            int y0=app.box.y;
            int w=app.stageRect.w;
            app.box.x+= safeStod(block.p1,10);
            if(app.box.x<=-w/2)
                app.box.x=-w/2;
            else if(app.box.x>=w/2)
                app.box.x=w/2;
            pening(app.isPenDown,app,x0,y0);
            std::string inf="[x"+std::to_string(int(x0))+"->"+std::to_string(int(app.box.x))+"]";
            LogEvent(app,line,"CHANGE_X",inf);
            break;

        }
        case changeYBy:{
            int x0=app.box.x;
            int y0=app.box.y;
            int h=app.stageRect.h;
            app.box.y+=safeStod(block.p1,10);
            if(app.box.y<=-h/2)
                app.box.y=-h/2;
            else if(app.box.y>=h/2)
                app.box.y=h/2;
            pening(app.isPenDown,app,x0,y0);
            std::string inf="[y"+std::to_string(int(y0))+"->"+std::to_string(int(app.box.y))+"]";
            LogEvent(app,line,"CHANGE_Y",inf);
            break;
        }
        case setXTo:{
            int x0=app.box.x;
            int y0=app.box.y;
            int w=app.stageRect.w;
            app.box.x= safeStod(block.p1,10);
            if(app.box.x<=-w/2)
                app.box.x=-w/2;
            else if(app.box.x>=w/2)
                app.box.x=w/2;
            pening(app.isPenDown,app,x0,y0);
            std::string inf="[x"+std::to_string(int(x0))+"->"+std::to_string(int(app.box.x))+"]";
            LogEvent(app,line,"SET_X",inf);
            break;
        }
        case setYTo:{
            int x0=app.box.x;
            int y0=app.box.y;
            int h=app.stageRect.h;
            app.box.y=safeStod(block.p1,10);
            if(app.box.y<=-h/2)
                app.box.y=-h/2;
            else if(app.box.y>=h/2)
                app.box.y=h/2;
            pening(app.isPenDown,app,x0,y0);
            std::string inf="[y"+std::to_string(int(y0))+"->"+std::to_string(int(app.box.y))+"]";
            LogEvent(app,line,"SET_Y",inf);
            break;
        }
        case goToRandomPosition:
        {    int x0=app.box.x;
            int y0=app.box.y;
            int h=app.stageRect.h;
            int w=app.stageRect.w;
            app.box.x=rand()%w-w/2;
            app.box.y=rand()%h-h/2;
            pening(app.isPenDown,app,x0,y0);
            std::string inf="[x"+std::to_string(int(x0))+"->"+std::to_string(int(app.box.x))+"] [y:"+std::to_string(int(y0))+"->"+std::to_string(int(app.box.y))+"]";
            LogEvent(app,line,"GOTO_RAND",inf);
            break;
        }
        case goToMousePointer:{
            int x0=app.box.x;
            int y0=app.box.y;
            int h=app.stageRect.h;
            int w=app.stageRect.w;
            int x=mouse.x-app.stageRect.x-app.stageRect.w/2;
            int y=mouse.y-app.stageRect.y-app.stageRect.h/2;
            app.box.x=x;
            app.box.y=-y;
            if(app.box.x<=-w/2)
                app.box.x=-w/2;
            else if(app.box.x>=w/2)
                app.box.x=w/2;
            if(app.box.y<=-h/2)
                app.box.y=-h/2;
            else if(app.box.y>=h/2)
                app.box.y=h/2;
            pening(app.isPenDown,app,x0,y0);
            std::string inf="[x"+std::to_string(int(x0))+"->"+std::to_string(app.box.x)+"] [y:"+std::to_string(y0)+"->"+std::to_string(app.box.y)+"]";
            LogEvent(app,line,"GOTO_MOUSE",inf);
            break;


        }
        case setSizeTo:{
            double size0=app.box.scale;
            int size= safeStod(block.p1,100);
            if(size<10)
                size=10;
            if(size>600)
                size=600;
            app.box.scale=size/100;
//            app.box.w=size/100.0*app.boxw;
//            app.box.h=size/100.0*app.boxh;
            std::string inf="[size"+std::to_string(size0)+"->"+std::to_string(app.box.scale)+"]";
            LogEvent(app,line,"SET_SIZE",inf);
            break;
        }
        case changeSizeBy:{
            double size0=app.box.scale;
            int size= safeStod(block.p1,10)/100+size0;
            if(size<0.1)
                size=0.1;
            if(size>6)
                size=6;
            app.box.scale=size;

            std::string inf="[size"+std::to_string(size0)+"->"+std::to_string(app.box.scale)+"]";
            LogEvent(app,line,"CHANGE_SIZE",inf);
            break;
        }
        case sayForSeconds:{
            std::string u=block.p1;

            if(u== ""){
                app.isSaying=false;
                app.say="";
                break;
            }
            app.isSaying= true;
            app.say=u;
            std::string inf="[say"+u+"->"+"for"+block.p2+"secconds]";
            LogEvent(app,line,"SAY_SEC",inf);

            break;
        }
        case thinkForSeconds:{
            std::string u=block.p1;
            if(u== ""){
                app.isThinking=false;
                app.think="";
                break;
            }
            app.isThinking= true;
            app.think=u;
            std::string inf="[think"+u+"->"+"for"+block.p2+"secconds]";
            LogEvent(app,line,"THINK_SEC",inf);
            break;
        }
        case say:{std::string u=block.p1;
            if(u== ""){
                app.isSaying=false;
                app.say="";
                break;
            }
            app.isSaying= true;
            app.say=u;
            std::string inf="[say"+u+"]";
            LogEvent(app,line,"SAY",inf);
            break;
        }
        case think:{
            std::string u=block.p1;
            if(u== ""){
                app.isThinking=false;
                app.think="";
                break;
            }
            app.isThinking= true;
            app.think=u;
            std::string inf="[think"+u+"]";
            LogEvent(app,line,"THINK",inf);
            break;}



        case show:{
            app.box.isShowing=true;
            LogEvent(app,line,"SHOW_SPRITE","");
            break;
        }
        case hide:{
            app.box.isShowing=false;
            LogEvent(app,line,"HIDE_SPRITE","");
        }
        case setColorEffect: {
            int y=app.colorEffect;
            app.colorEffect = safeStod(block.p1,0);
            std::string inf="[color"+std::to_string(y)+"->"+std::to_string(app.colorEffect)+"]";
            LogEvent(app,line,"SET_COLOR",inf);
            break;
        }

        case setFishEye: {
            int y=app.brightnessEffect;
            app.brightnessEffect = safeStod(block.p1,0);
            std::string inf="[brightness"+std::to_string(y)+"->"+std::to_string(app.brightnessEffect)+"]";
            LogEvent(app,line,"SET_BRIGTNESS",inf);

            break;
        }
        case setWhirlEffect: {
            int y=app.ghostEffect;
            app.ghostEffect= safeStod(block.p1,0);
            std::string inf="[ghost"+std::to_string(y)+"->"+std::to_string(app.ghostEffect)+"]";
            LogEvent(app,line,"SET_GHOST",inf);

            break;
        }
        case  clearGraphicEffect: {
            app.colorEffect = 0;
            app.brightnessEffect = 0;
            app.ghostEffect = 0;
            app.lastAppliedColorEffect = -999;
            if (app.boxEffectTexture) {
                SDL_DestroyTexture(app.boxEffectTexture);
                app.boxEffectTexture = nullptr;
            }
            if (app.box.t) {
                SDL_SetTextureColorMod(app.box.t, 255, 255, 255);
                SDL_SetTextureAlphaMod(app.box.t, 255);
            }
            LogEvent(app,line,"CLEAR_GFX","");
            break;
        }

        case penDown:{
            app.isPenDown= true;
            LogEvent(app,line,"PENISDOWN","");
            break;
        }
        case penUp:{
            app.isPenDown=false;
            LogEvent(app,line,"PENISUP","");
            break;
        }
        case eraseAll: {
            clearPenTexture(app);
            LogEvent(app,line,"PENERASE","");
            break;
        }
        case stamp:{
            Stamp (app);
            LogEvent(app,line,"SPRITESTAMPED","");
            break;

        }
        case setPenColorTo:{
            app.pen=block.color;
            app.ghostEffect= safeStod(block.p1,0);
            LogEvent(app,line,"PENCOLORCHANGED","");
            break;
        }
        case setPenBrightnees:{
            int b= safeStod(block.p1,50);
            app.pen= setBrightness(app.pen,b);
            LogEvent(app,line,"PENBRIGHTNESSCHANGED","");

            break;
        }
        case setPenSaturation:{
            int b= safeStod(block.p1,50);
            app.pen= setSaturation(app.pen,b);
            LogEvent(app,line,"PENSATUATIONCHANGED","");
            break;
        }
        case waitSecondes:{
            std::string inf="[ waiting for "+block.p1+"seconds]";
            LogEvent(app,line,"WAITING",inf);

            break;
        }
        case whenGreenFlagClicked:{
            LogEvent(app,line,"START","");
        }


    }
    UpdateSpriteState(tabs,app);
}
void inverseRoundedBoxRGBA(SDL_Renderer* renderer,int x1, int y1, int x2, int y2,int radius,Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);
    int w = x2 - x1;
    int h = y2 - y1;
    if (radius > w / 2) radius = w / 2;
    if (radius > h / 2) radius = h / 2;
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    for (int dy = 0; dy < radius; dy++) {
        int circleX = (int)sqrt((double)(radius * radius - (radius - dy) * (radius - dy)));
        int fillWidth = radius - circleX;
        if (fillWidth <= 0) continue;
        SDL_RenderDrawLine(renderer,x1, y1 + dy,x1 + fillWidth - 1, y1 + dy);
        SDL_RenderDrawLine(renderer,x2 - fillWidth, y1 + dy,x2 - 1, y1 + dy);
        SDL_RenderDrawLine(renderer,x1, y2 - 1 - dy,x1 + fillWidth - 1, y2 - 1 - dy);
        SDL_RenderDrawLine(renderer,x2 - fillWidth, y2 - 1 - dy,x2 - 1, y2 - 1 - dy);
    }
}
void rgbToHsv(Uint8 r, Uint8 g, Uint8 b, float &h, float &s, float &v) {
    float rf = r / 255.0f, gf = g / 255.0f, bf = b / 255.0f;
    float maxc = fmax(rf, fmax(gf, bf));
    float minc = fmin(rf, fmin(gf, bf));
    float diff = maxc - minc;
    v = maxc;
    s = (maxc == 0) ? 0 : (diff / maxc);
    if (diff == 0) {
        h = 0;
    } else if (maxc == rf) {
        h = 60.0f * fmod((gf - bf) / diff, 6.0f);
    } else if (maxc == gf) {
        h = 60.0f * ((bf - rf) / diff + 2.0f);
    } else {
        h = 60.0f * ((rf - gf) / diff + 4.0f);
    }
    if (h < 0) h += 360.0f;
}
void hsvToRgb(float h, float s, float v, Uint8 &r, Uint8 &g, Uint8 &b) {
    float c = v * s;
    float x = c * (1.0f - fabs(fmod(h / 60.0f, 2.0f) - 1.0f));
    float m = v - c;
    float r1, g1, b1;
    if      (h < 60)  { r1 = c; g1 = x; b1 = 0; }
    else if (h < 120) { r1 = x; g1 = c; b1 = 0; }
    else if (h < 180) { r1 = 0; g1 = c; b1 = x; }
    else if (h < 240) { r1 = 0; g1 = x; b1 = c; }
    else if (h < 300) { r1 = x; g1 = 0; b1 = c; }
    else              { r1 = c; g1 = 0; b1 = x; }
    r = (Uint8)((r1 + m) * 255);
    g = (Uint8)((g1 + m) * 255);
    b = (Uint8)((b1 + m) * 255);
}
SDL_Color setBrightness(SDL_Color color, float amount) {
    float h, s, v;
    rgbToHsv(color.r, color.g, color.b, h, s, v);
    float norm = amount / 100.0f;
    if (norm > 0) {
        v = v + (1.0f - v) * norm;
        s = s * (1.0f - norm);
    } else {
        v = v * (1.0f + norm);
    }

    v = fmax(0.0f, fmin(1.0f, v));
    s = fmax(0.0f, fmin(1.0f, s));
    Uint8 r, g, b;
    hsvToRgb(h, s, v, r, g, b);
    return {r, g, b, color.a};
}
SDL_Color setSaturation(SDL_Color color, float amount) {


    float h, s, v;
    rgbToHsv(color.r, color.g, color.b, h, s, v);

    float norm = amount / 100.0f;

    if (norm > 0) {
        s = s + (1.0f - s) * norm;
    } else {
        s = s * (1.0f + norm);
    }

    s = fmax(0.0f, fmin(1.0f, s));

    Uint8 r, g, b;
    hsvToRgb(h, s, v, r, g, b);

    return {r, g, b, color.a};
}
SDL_Texture* createHueShiftedTexture(SDL_Renderer* renderer,SDL_Surface* original,float colorEffect) {
    SDL_Surface* copy = SDL_ConvertSurfaceFormat(original, SDL_PIXELFORMAT_RGBA32, 0);
    if (!copy) return nullptr;
    SDL_LockSurface(copy);
    Uint32* pixels = (Uint32*)copy->pixels;
    int pixelCount = copy->w * copy->h;
    float hueShift = fmod(colorEffect * 1.8f, 360.0f);
    if (hueShift < 0) hueShift += 360.0f;
    for (int i = 0; i < pixelCount; i++) {
        Uint8 r, g, b, a;
        SDL_GetRGBA(pixels[i], copy->format, &r, &g, &b, &a);
        if (a == 0) continue;
        float h, s, v;
        rgbToHsv(r, g, b, h, s, v);
        h = fmod(h + hueShift, 360.0f);
        Uint8 nr, ng, nb;
        hsvToRgb(h, s, v, nr, ng, nb);
        pixels[i] = SDL_MapRGBA(copy->format, nr, ng, nb, a);
    }
    SDL_UnlockSurface(copy);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, copy);
    SDL_FreeSurface(copy);
    if (tex) {
        SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
    }
    return tex;
}
SDL_Texture* createGhostTexture(SDL_Renderer* renderer, SDL_Surface* original, float brightnessEffect) {


    SDL_Surface* copy = SDL_ConvertSurfaceFormat(original, SDL_PIXELFORMAT_RGBA32, 0);
    if (!copy) return nullptr;

    SDL_LockSurface(copy);
    Uint32* pixels = (Uint32*)copy->pixels;
    int pixelCount = copy->w * copy->h;

    float brightness = brightnessEffect;
    if (brightness > 100.0f)  brightness = 100.0f;
    if (brightness < -100.0f) brightness = -100.0f;

    float factor = brightness / 100.0f;  // -1.0 تا +1.0

    for (int i = 0; i < pixelCount; i++) {
        Uint8 r, g, b, a;
        SDL_GetRGBA(pixels[i], copy->format, &r, &g, &b, &a);
        if (a == 0) continue;

        float rf = (float)r;
        float gf = (float)g;
        float bf = (float)b;

        if (factor >= 0) {

            rf = rf + (255.0f - rf) * factor;
            gf = gf + (255.0f - gf) * factor;
            bf = bf + (255.0f - bf) * factor;
        } else {

            float absFactor = -factor;  // 0.0 تا 1.0
            rf = rf * (1.0f - absFactor);
            gf = gf * (1.0f - absFactor);
            bf = bf * (1.0f - absFactor);
        }


        Uint8 nr = (Uint8)(rf < 0 ? 0 : (rf > 255 ? 255 : rf));
        Uint8 ng = (Uint8)(gf < 0 ? 0 : (gf > 255 ? 255 : gf));
        Uint8 nb = (Uint8)(bf < 0 ? 0 : (bf > 255 ? 255 : bf));

        pixels[i] = SDL_MapRGBA(copy->format, nr, ng, nb, a);
    }

    SDL_UnlockSurface(copy);

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, copy);
    SDL_FreeSurface(copy);

    if (tex) {
        SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
    }
    return tex;
}
SDL_Texture* createBrightnessTexture(SDL_Renderer* renderer,SDL_Surface* originalSurface,float brightness)
{
    // brightness: -100 to +100 (like Scratch)
    if (!originalSurface) return nullptr;

    SDL_Surface* copy = SDL_ConvertSurfaceFormat(
            originalSurface, SDL_PIXELFORMAT_ARGB8888, 0
    );
    if (!copy) return nullptr;

    SDL_LockSurface(copy);

    Uint32* pixels = (Uint32*)copy->pixels;
    int pixelCount = copy->w * copy->h;

    // Exact Scratch formula:
    // u_brightness = clamp(brightness, -100, 100) / 100.0
    // RGB_new = clamp(RGB_old + u_brightness, 0.0, 1.0)
    if (brightness > 100.0f) brightness = 100.0f;
    if (brightness < -100.0f) brightness = -100.0f;

    float brightnessNorm = brightness / 100.0f;  // -1.0 to +1.0
    int brightnessInt = (int)(brightnessNorm * 255.0f); // -255 to +255

    for (int i = 0; i < pixelCount; i++) {
        Uint8 a = (pixels[i] >> 24) & 0xFF;
        Uint8 r = (pixels[i] >> 16) & 0xFF;
        Uint8 g = (pixels[i] >> 8)  & 0xFF;
        Uint8 b =  pixels[i]        & 0xFF;

        if (a == 0) continue;

        // Scratch exact: clamp(channel + brightness * 255, 0, 255)
        int ri = r + brightnessInt;
        int gi = g + brightnessInt;
        int bi = b + brightnessInt;

        if (ri > 255) ri = 255; if (ri < 0) ri = 0;
        if (gi > 255) gi = 255; if (gi < 0) gi = 0;
        if (bi > 255) bi = 255; if (bi < 0) bi = 0;

        pixels[i] = ((Uint32)a << 24) | ((Uint32)ri << 16) |
                    ((Uint32)gi << 8) | (Uint32)bi;
    }

    SDL_UnlockSurface(copy);

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, copy);
    SDL_FreeSurface(copy);
    return tex;
}
void pening(bool isp,AppState & app,int x1,int y1){
    if (!isp)
        return;
    int X1=app.stageRect.w/2+x1;
    int Y1=-y1+app.stageRect.h/2;
    int X2=app.stageRect.w/2+app.box.x;
    int Y2=-app.box.y+app.stageRect.h/2;

    SDL_SetRenderTarget(app.renderer,app.penTexture);
    aalineRGBA(app.renderer,X1,Y1-1,X2,Y2-1,app.pen.r,app.pen.g,app.pen.b,app.pen.a);
    aalineRGBA(app.renderer,X1,Y1,X2,Y2,app.pen.r,app.pen.g,app.pen.b,app.pen.a);
    //aalineRGBA(app.renderer,X1,Y1+1,X2,Y2+1,app.pen.r,app.pen.g,app.pen.b,app.pen.a);
    SDL_SetRenderTarget(app.renderer, nullptr);
    return;
}
void clearPenTexture(AppState& app) {
    if (app.penTexture) {
        SDL_SetRenderTarget(app.renderer, app.penTexture);
        SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 0);
        SDL_RenderClear(app.renderer);
        SDL_SetRenderTarget(app.renderer, nullptr);
    }
}
void Stamp(AppState& app){
    if(!app.box.t||!app.penTexture) return;
    SDL_SetRenderTarget(app.renderer,app.penTexture);
    int X=app.box.x+app.stageRect.w/2-app.box.w/2;
    int Y=-app.box.y+app.stageRect.h/2-app.box.h/2;
    SDL_Rect u={X,Y,int(app.box.w),int(app.box.h)};
    SDL_Texture* texToStamp;
    if (app.boxghostTexture) {
        texToStamp = app.boxghostTexture;
    } else if (app.boxBrightnessTexture) {
        texToStamp = app.boxBrightnessTexture;
    } else if (app.boxEffectTexture) {
        texToStamp = app.boxEffectTexture;
    } else {
        texToStamp = app.box.t;
    }
    double renderAngle = app.box.angle - 90.0;
    SDL_RenderCopyEx(app.renderer,texToStamp,nullptr,&u,renderAngle,nullptr,SDL_FLIP_NONE);
    SDL_SetRenderTarget(app.renderer, nullptr);
}
void LogEvent(AppState&app,int line, const std::string& cmd, const std::string&  inf) {

    std::string h="[Cycle:"+ std::to_string(app.cycle)+"] [Line: "+std::to_string(line)+"] [CMD: "+cmd+"]->"+inf;
    app.LOG.push_back(h);
}
void PrintLog(AppState &app) {
    for (int i = app.logPrintedIndex; i < (int)app.LOG.size(); i++) {
        std::cout << app.LOG[i] << std::endl;
    }
    app.logPrintedIndex = (int)app.LOG.size();
}