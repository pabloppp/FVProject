#ifndef GUI_HPP
#define	GUI_HPP

#include "facade/Vector2.hpp"
#include "facade/Texture.hpp"


namespace gme{
    
class GUI {
public:
    struct Color{
        Color(){};
        Color(int nr, int ng, int nb, int na = 255){
            r = nr;
            g = ng;
            b = nb;
            a = na;
        };
        int r = 0;
        int g = 0;
        int b = 0;
        int a = 0;
    };
    struct TextureName{
        TextureName(const std::string &str){
            path = str;
        };
        TextureName(){
            path = "";
        };
        std::string path;
    };
    
    enum Origin {
        Center = 0,
        TopLeft,
        TopRight,
        TopCenter,
        CenterLeft,
        CenterRight,
        BottomLeft,
        BottomRight,
        BottomCenter
    };
    
    enum ScaleMode {
        StretchToFill = 0,
        ScaleAndCrop,
        ScaleToFit
    };
    
    static Color backgroundColor;
    static Color tintColor;
    static Color outlineColor;
    static Color contentColor;
    
    static Color red;
    static Color green;
    static Color blue;
    static Color white;
    static Color transparent;
    
    static bool enabled;
    static int fontSize;
    static float outlineThickness;
    
    static void box(Vector2 position, Vector2 size, const std::string &text = "", Origin origin = Origin::TopLeft, Texture *texture = NULL);
    static void box(Vector2 position, Vector2 size, Origin origin, Texture *texture = NULL);
    static void box(Vector2 position, Vector2 size, const std::string &text, Origin origin, TextureName w);
    static void box(Vector2 position, Vector2 size, const std::string &text, TextureName w);
    static void box(Vector2 position, Vector2 size, Origin origin, TextureName w);
    static void box(Vector2 position, Vector2 size, TextureName w);
    static void label(Vector2 position, const std::string &txt, Origin origin = Origin::TopLeft);
    static void loadFont(const std::string path);
    static void drawTexture(Vector2 position, Vector2 size, Texture *texture, Origin origin = Origin::TopLeft, ScaleMode mode = ScaleMode::StretchToFill);
    static void drawTexture(Vector2 position, Vector2 size, TextureName w, Origin origin = Origin::TopLeft, ScaleMode mode = ScaleMode::StretchToFill);
    static void drawTexture(Vector2 position, TextureName w, Origin origin = Origin::TopLeft);

    static sf::Font font;
private:
};    

}

#endif	/* GUI_HPP */

