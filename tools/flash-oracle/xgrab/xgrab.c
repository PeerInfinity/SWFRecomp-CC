/* xgrab: dump the X window tree (to stderr) and write the root window as a
 * binary PPM (to argv[1]). Used by run_image.py --screen to screenshot the
 * Flash projector under Xvfb.
 *
 * xgrab --type TEXT [delay_ms]: give the largest toplevel window keyboard
 * focus (no click), then type TEXT with XTest, delay_ms between characters
 * (default 150). Used by run_trace.py --type for input-driven fixtures.
 *
 * Build: gcc -O2 -o xgrab xgrab.c -lX11 -lXtst */
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/extensions/XTest.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static Window best_win; static int best_area, best_x, best_y, best_w, best_h;

static void tree(Display *d, Window w, int depth, int ox, int oy) {
    XWindowAttributes a;
    if (!XGetWindowAttributes(d, w, &a)) return;
    char *name = NULL;
    XFetchName(d, w, &name);
    if (a.map_state == IsViewable && depth > 0 && a.width * a.height > best_area && a.width < 4000) {
        best_area = a.width * a.height; best_win = w;
        best_x = ox + a.x; best_y = oy + a.y; best_w = a.width; best_h = a.height;
    }
    if (a.map_state == IsViewable)
        fprintf(stderr, "%*sWIN 0x%lx abs=%d,%d size=%dx%d name=%s\n", depth * 2, "", w,
                ox + a.x, oy + a.y, a.width, a.height, name ? name : "");
    if (name) XFree(name);
    Window root, parent, *kids = NULL;
    unsigned n = 0;
    if (XQueryTree(d, w, &root, &parent, &kids, &n)) {
        for (unsigned i = 0; i < n; i++) tree(d, kids[i], depth + 1, ox + a.x + a.border_width, oy + a.y + a.border_width);
        if (kids) XFree(kids);
    }
}

int main(int argc, char **argv) {
    Display *d = XOpenDisplay(NULL);
    if (!d) { fprintf(stderr, "no display\n"); return 1; }
    Window r = DefaultRootWindow(d);
    if (argc >= 3 && strcmp(argv[1], "--type") == 0) {
        /* toplevel children of root only, so the root itself is skipped */
        Window rr, pp, *kids = NULL; unsigned n = 0;
        XQueryTree(d, r, &rr, &pp, &kids, &n);
        for (unsigned i = 0; i < n; i++) tree(d, kids[i], 1, 0, 0);
        if (!best_win) { fprintf(stderr, "no window\n"); return 1; }
        int delay = argc >= 4 ? atoi(argv[3]) : 150;
        XSetInputFocus(d, best_win, RevertToParent, CurrentTime);
        /* No click: clicking empty stage clears Flash's text focus (measured
         * on avm1_edittext_html_typed_runs). Keyboard focus on the toplevel
         * is enough for Selection.setFocus'd fields. */
        XSync(d, False); usleep(delay * 1000);
        for (const char *c = argv[2]; *c; c++) {
            char name[2] = {*c, 0};
            KeySym ks = XStringToKeysym(name);
            KeyCode kc = XKeysymToKeycode(d, ks);
            int shift = (*c >= 'A' && *c <= 'Z');
            KeyCode sk = XKeysymToKeycode(d, XK_Shift_L);
            if (shift) XTestFakeKeyEvent(d, sk, True, 0);
            XTestFakeKeyEvent(d, kc, True, 0); XTestFakeKeyEvent(d, kc, False, 0);
            if (shift) XTestFakeKeyEvent(d, sk, False, 0);
            XFlush(d); usleep(delay * 1000);
        }
        fprintf(stderr, "typed into 0x%lx %dx%d\n", best_win, best_w, best_h);
        return 0;
    }
    tree(d, r, 0, 0, 0);
    if (argc < 2) return 0;
    XWindowAttributes a;
    XGetWindowAttributes(d, r, &a);
    XImage *im = XGetImage(d, r, 0, 0, a.width, a.height, AllPlanes, ZPixmap);
    if (!im) { fprintf(stderr, "XGetImage failed\n"); return 1; }
    FILE *f = fopen(argv[1], "wb");
    fprintf(f, "P6\n%d %d\n255\n", a.width, a.height);
    for (int y = 0; y < a.height; y++)
        for (int x = 0; x < a.width; x++) {
            unsigned long p = XGetPixel(im, x, y);
            unsigned char rgb[3] = {(p >> 16) & 255, (p >> 8) & 255, p & 255};
            fwrite(rgb, 1, 3, f);
        }
    fclose(f);
    return 0;
}
