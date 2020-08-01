#include "tiny.h"
#include "flowers.h"
#include "background.h"

rkExportLib(daisies)

rkType(SeedComponent,   rkParent(tiny::component) rkDefaultFactory)
rkType(FlowerComponent, rkParent(tiny::component) rkDefaultFactory)
rkType(FlowerManager,   rkParent(tiny::job)       rkDefaultFactory)

rkType(SkyComponent,      rkParent(tiny::component) rkDefaultFactory)
rkType(CloudComponent,    rkParent(tiny::component) rkDefaultFactory)
rkType(GroundComponent,   rkParent(tiny::component) rkDefaultFactory)
rkType(BackgroundManager, rkParent(tiny::job)       rkDefaultFactory)

#ifdef DAISY_SCRNSVR
#include "screensaver.h"

rkType(Win32ScreensaverWindow, rkParent(tiny::window) rkDefaultFactory)

#endif