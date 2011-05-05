
// This class helps dealing with high res displays such as iPhone's
// Retina Display.
// This class looks very dull if you are reading it in a .pde file
// but it is trasparently replaced by the transator with a more
// complicated class that invokes a lower-level function.
// The reason why the class is here in this form is so that one
// can build sketches that work both in processing and mobile devices.

// Note that although in theory this mechanism would support
// screens of arbitrary pixel density, the reality of things is that
// screens won't realistically go beyond the density of the Retina display
// (wich has 4 times the pixel density of a normal screen), since
// higher densities are not needed. And also
// there won't ever be a need to manage pixel densities between 1 and 4,
// because those scalings would make it far too hard to repurpose
// content and programs that were originaly done for 1x.
// In other words, this class really will only ever work to conform to
// a pixel density of 4 times the one of regular screens, so the variable
// dpiScaleFactor below will only ever be 1.0 or 2.0

// Note also that vector graphics doesn't need to be managed: it transparently
// gets rendered at the native resolution of the screen keeping the same
// perceived size and proportions on screen. So are mouse events, the input
// gets scaled so that the numbers describing the pointer (or fingers) positions
// are as if the device had a 1x screen

// The problem comes with bitmap data that you either load from files
// or generate programmatically. In that case for high-resolution
// displays it is better to generate/load a bitmap that is twice the
// normal size - so one needs to be aware of whether the screen is high dpi
// or not.

static class HighDpiScreenManager {
  static float dpiScaleFactor = 1.0;
}

