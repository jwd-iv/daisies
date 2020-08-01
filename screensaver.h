#pragma once

#include "tiny/sfml/gfx/renderer.h"
#include "tiny/sfml/system/window.h"

class Win32ScreensaverWindow : SFMLWindow
{
public:
  // Inherited via window
  virtual void initialize() override;

  virtual void update(float dt) override;

  virtual void close() override;

  virtual bool is_active() const override;

  virtual bool show() override;

  virtual bool hide() override;

  virtual unsigned width() const override;

  virtual unsigned height() const override;

  virtual bool is_fullscreen() const override;

  virtual void render() override;

  virtual bool set_size(unsigned w, unsigned h, bool fullscreen = false) override;

  rkMetaHook(Win32ScreensaverWindow);
};
