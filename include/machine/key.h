/*---------------------------------------------------------------------------*
 * Operating Systems I                                                       *
 *---------------------------------------------------------------------------*
 *                                                                           *
 *                                K E Y                                      *
 *                                                                           *
 *---------------------------------------------------------------------------*/

#ifndef __Key_include__
#define __Key_include__

/** \brief Translator between scancodes ASCII-code and modifier bits.
 */
class Key {
  unsigned char asc;
  unsigned char scan;
  unsigned char modi;

  struct mbit {
  	enum {
      shift      = 1,
  	   alt_left    = 2,
  	   alt_right   = 4,
  	   ctrl_left   = 8,
  	   ctrl_right  = 16,
  	   caps_lock   = 32,
  	   num_lock    = 64,
  	   scroll_lock = 128
  	};
  };

public:
  /** \brief Default constructor setring ASCII, scancode and modifier to 0
   *
   * A freshly constructed key is invalid.
   */
  Key () : asc (0), scan (0), modi (0) {}

  /** \brief test for validity.
   *
   * return  false if scancode is 0, true otherwise
   */
  bool valid ()      { return scan != 0; }

  /** \brief invalidate this key
   *
   * By setting the scancode to 0 this key will be invalid
   */
  void invalidate () { scan = 0; }

  /** \brief set ascii value
   *
   * \param a the new ascii value
   **/
  void ascii (unsigned char a) { asc = a; }

  /** \brief set scancode value
   *
   * \param s the new scancode value
   **/
  void scancode (unsigned char s) { scan = s; }

  /** \brief get ascii value
   *
   * \return the current ascii value contained in this key
   **/
  unsigned char ascii () const { return asc; }

  /** \brief get scancode value
   *
   * \return the current scancode value contained in this key
   **/
  unsigned char scancode () const { return scan; }

  void shift (bool pressed)
    { modi = pressed ? modi | mbit::shift : modi & ~mbit::shift; }
  void alt_left (bool pressed)
    { modi = pressed ? modi | mbit::alt_left : modi & ~mbit::alt_left; }
  void alt_right (bool pressed)
    { modi = pressed ? modi | mbit::alt_right : modi & ~mbit::alt_right; }
  void ctrl_left (bool pressed)
    { modi = pressed ? modi | mbit::ctrl_left : modi & ~mbit::ctrl_left; }
  void ctrl_right (bool pressed)
    { modi = pressed ? modi | mbit::ctrl_right : modi & ~mbit::ctrl_right; }
  void caps_lock (bool pressed)
    { modi = pressed ? modi | mbit::caps_lock : modi & ~mbit::caps_lock; }
  void num_lock (bool pressed)
    { modi = pressed ? modi | mbit::num_lock : modi & ~mbit::num_lock; }
  void scroll_lock (bool pressed)
    { modi = pressed ? modi | mbit::scroll_lock : modi & ~mbit::scroll_lock; }

  // methods to get the information of the keys: SHIFT, ALT, CTRL, ...
  bool shift ()       { return modi & mbit::shift; }
  bool alt_left ()    { return modi & mbit::alt_left; }
  bool alt_right ()   { return modi & mbit::alt_right; }
  bool ctrl_left ()   { return modi & mbit::ctrl_left; }
  bool ctrl_right ()  { return modi & mbit::ctrl_right; }
  bool caps_lock ()   { return modi & mbit::caps_lock; }
  bool num_lock ()    { return modi & mbit::num_lock; }
  bool scroll_lock () { return modi & mbit::scroll_lock; }
  bool alt ()         { return alt_left ()  | alt_right (); }
  bool ctrl ()        { return ctrl_left () | ctrl_right (); }

  /** \brief overloded cast operator
   *
   * Can be used to cast this key to an ascii char.
   *
   * \return the ascii value of this key contained in a char
   **/
  operator char ()    { return (char) asc; }

  struct scan { 
  	enum {
      f1 = 0x3d, del = 0x53, up=72, down=80, left=75, right=77,
      div = 8
  	};
  };
};

#endif
