#pragma once

#include <cstdint>
#include <chrono>
#include <Components/Gfx/Gfx.h>
#include "Screen.h"
#include <bits/unique_ptr.h>
#include "../Fonts/lcdfont14.h"
#include "../Fonts/lcdfont70.h"
#include "../../Version.h"
#include <lvgl/src/lv_core/lv_style.h>

namespace Pinetime {
  namespace Applications {
    namespace Screens {
      class Message : public Screen{
        public:
          explicit Message(DisplayApp* app, Components::Gfx& gfx);
          ~Message() override;
          void Refresh(bool fullRefresh) override;
          void OnObjectEvent(lv_obj_t* obj, lv_event_t event);
          void OnButtonPushed() override { nextScreen = Screen::NextScreen::Menu; }

        private:
          const FONT_INFO largeFont {lCD_70ptFontInfo.height, lCD_70ptFontInfo.startChar, lCD_70ptFontInfo.endChar, lCD_70ptFontInfo.spacePixels, lCD_70ptFontInfo.charInfo, lCD_70ptFontInfo.data};
          const FONT_INFO smallFont {lCD_14ptFontInfo.height, lCD_14ptFontInfo.startChar, lCD_14ptFontInfo.endChar, lCD_14ptFontInfo.spacePixels, lCD_14ptFontInfo.charInfo, lCD_14ptFontInfo.data};

          lv_style_t* labelStyle;
          lv_obj_t * label;
          lv_obj_t* backgroundLabel;
          lv_obj_t * button;
          lv_obj_t * labelClick;

          uint32_t clickCount = 0 ;
          uint32_t previousClickCount = 0;
      };
    }
  }
}
