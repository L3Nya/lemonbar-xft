#include <err.h>
#include <X11/Xft/Xft.h>

int main(int argc, char **argv) {
  Display *dpy = XOpenDisplay(getenv("DISPLAY"));
  if (!dpy) errx(1, "failed to open display %s", getenv("DISPLAY"));
  if (argc != 3) errx(1, "usage: xft_str_box font text-string");

  XftFont *font = XftFontOpenName(dpy, DefaultScreen(dpy), argv[1]);
  if (!font) errx(1, "no font match");

  XGlyphInfo info;
  XftTextExtentsUtf8(dpy, font, (FcChar8*)argv[2], strlen(argv[2]), &info);
  printf("%d %d\n", info.width, info.height);
}
