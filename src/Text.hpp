#ifndef TEXT_H
#define TEXT_H

#include <SDL_render.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>
class Text {
public:
  Text();
  Text(std::string str,  TTF_Font &font, SDL_Color color);
  ~Text();

  void SetText(const std::string &str);
  void SetFont(TTF_Font &font);
  void RenderTexture(SDL_Renderer* renderer);

private:
  std::unique_ptr<SDL_Texture> m_Texture;
  std::string m_Text;
  TTF_Font *m_Font;
  SDL_Color m_Color;
  
};

#endif
