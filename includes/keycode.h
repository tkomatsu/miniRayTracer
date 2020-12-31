/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 22:37:00 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/12/28 22:42:37 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24
# define RESIZEREQUEST 25
# define CIRCULATENOTIFY 26
# define CIRCULATEREQUEST 27
# define PROPERTYNOTIFY 28
# define SELECTIONCLEAR 29
# define SELECTIONREQUEST 30
# define SELECTIONNOTIFY 31
# define COLORMAPNOTIFY 32
# define CLIENTMESSAGE 33
# define MAPPINGNOTIFY 34
# define GENERICEVENT 35
# define LASTEVENT 36

# define NOEVENTMASK 0L
# define KEYPRESSMASK 1L
# define KEYRELEASEMASK 2L
# define BUTTONPRESSMASK 4L
# define BUTTONRELEASEMASK 8L
# define ENTERWINDOWMASK 16L
# define LEAVEWINDOWMASK 32L
# define POINTERMOTIONMASK 64L
# define POINTERMOTIONHINTMASK 128L
# define BUTTON1MOTIONMASK 256L
# define BUTTON2MOTIONMASK 512L
# define BUTTON3MOTIONMASK 1024L
# define BUTTON4MOTIONMASK 2048L
# define BUTTON5MOTIONMASK 4096L
# define BUTTONMOTIONMASK 8192L
# define KEYMAPSTATEMASK 16384L
# define EXPOSUREMASK 32768L
# define VISIBILITYCHANGEMASK 65536L
# define STRUCTURENOTIFYMASK 131072L
# define RESIZEREDIRECTMASK 262144L
# define SUBSTRUCTURENOTIFYMASK 524288L
# define SUBSTRUCTUREREDIRECTMASK 1048576L
# define FOCUSCHANGEMASK 2097152L
# define PROPERTYCHANGEMASK 4194304L
# define COLORMAPCHANGEMASK 8388608L
# define OWNERGRABBUTTONMASK 16777216L

/*
** Keyboard keys
*/

/*
** Letters keys
*/

# ifdef LINUX
#  define A_KEY 97
#  define B_KEY 98
#  define C_KEY 99
#  define D_KEY 100
#  define E_KEY 101
#  define F_KEY 102
#  define G_KEY 103
#  define H_KEY 104
#  define I_KEY 105
#  define J_KEY 106
#  define K_KEY 107
#  define L_KEY 108
#  define M_KEY 109
#  define N_KEY 110
#  define O_KEY 111
#  define P_KEY 112
#  define Q_KEY 113
#  define R_KEY 114
#  define S_KEY 115
#  define T_KEY 116
#  define U_KEY 117
#  define V_KEY 118
#  define W_KEY 119
#  define X_KEY 120
#  define Y_KEY 121
#  define Z_KEY 122
# else
#  define A_KEY 97
#  define B_KEY 11
#  define C_KEY 8
#  define D_KEY 100
#  define E_KEY 14
#  define F_KEY 3
#  define G_KEY 5
#  define H_KEY 4
#  define I_KEY 34
#  define J_KEY 38
#  define K_KEY 40
#  define L_KEY 37
#  define M_KEY 46
#  define N_KEY 45
#  define O_KEY 31
#  define P_KEY 35
#  define Q_KEY 12
#  define R_KEY 15
#  define S_KEY 115
#  define T_KEY 17
#  define U_KEY 32
#  define V_KEY 9
#  define W_KEY 119
#  define X_KEY 7
#  define Y_KEY 16
#  define Z_KEY 6
# endif

/*
** Numbers (not numeric keypad ones)
*/

# ifdef LINUX
#  define K1_KEY 49
#  define K2_KEY 50
#  define K3_KEY 51
#  define K4_KEY 52
#  define K5_KEY 53
#  define K6_KEY 54
#  define K7_KEY 55
#  define K8_KEY 56
#  define K9_KEY 57
#  define K0_KEY 48
# else
#  define K1_KEY 18
#  define K2_KEY 19
#  define K3_KEY 20
#  define K4_KEY 21
#  define K5_KEY 23
#  define K6_KEY 22
#  define K7_KEY 26
#  define K8_KEY 28
#  define K9_KEY 25
#  define K0_KEY 29
# endif

/*
** Special characters
** SP_KEY is the space ( ) key
** BQ_KEY is the back quote (`) and tilde (~) key
** MN_KEY is the minus (-) and underscore (_) key
** PL_KEY is the plus (+) and equal (=) key
** SBO_KEY is the square bracket opening ([) and brace opening ({) key
** SBC_KEY is the square bracket closing (]) and brace closing (}) key
** BSL_KEY is the backslash (\) and pipe (|) key
** SC_KEY is the semicolon (;) and colon (:) key
** SQ_KEY is the simple quote (') and double quote (") key
** CM_KEY is the comma (,) and angle bracket opening (<) key
** PT_KEY is the point (.) and angle bracket closing (>) key
** SL_KEY is the slash (/) and question mark (?) key
*/

# ifdef LINUX
#  define SP_KEY 32
#  define BQ_KEY 96
#  define MN_KEY 45
#  define PL_KEY 61
#  define SBO_KEY 91
#  define SBC_KEY 93
#  define BSL_KEY 92
#  define SC_KEY 59
#  define SQ_KEY 39
#  define CM_KEY 44
#  define PT_KEY 46
#  define SL_KEY 47
# else
#  define SP_KEY 49
#  define BQ_KEY 50
#  define MN_KEY 27
#  define PL_KEY 24
#  define SBO_KEY 33
#  define SBC_KEY 30
#  define BSL_KEY 42
#  define SC_KEY 41
#  define SQ_KEY 39
#  define CM_KEY 43
#  define PT_KEY 47
#  define SL_KEY 44
# endif

/*
** Arrow keys
*/

# ifdef OSX
#  define UP_KEY 126
#  define DOWN_KEY 125
#  define RIGHT_KEY 65363
#  define LEFT_KEY 65361
# endif

/*
** Special keys
** CL_KEY is the caps lock key
** LSFT_KEY and RLFT_KEY are the left shift and right shift keys
** LCTRL_KEY and RCTRL_KEY are the left control and right control keys
** LOPT_KEY and ROPT_KEY are the left option and right option keys
** LCMD_KEY and RCMD_KEY are the left command and right command keys
** LDEL_KEY and RDEL_KEY are the left delete and right delete keys
** RTN_KEY is the return key
** EJ_KEY is the eject key and doesn't react
** PUP_KEY and PDOWN_KEY are the page up and page down keys
** CLR_KEY is the clear key
*/

# ifdef LINUX
#  define ESC_KEY 65307
#  define TAB_KEY 65289
#  define CL_KEY 65507
#  define LSFT_KEY 65505
#  define LCTRL_KEY 65507
#  define LOPT_KEY 65513
#  define RTN_KEY 65293
#  define RSFT_KEY 65506
#  define ROPT_KEY 65514
#  define RDEL_KEY 65288
# else
#  define ESC_KEY 53
#  define TAB_KEY 48
#  define CL_KEY 272
#  define LSFT_KEY 65505
#  define LCTRL_KEY 256
#  define LOPT_KEY 261
#  define LCMD_KEY 259
#  define LDEL_KEY 51
#  define RTN_KEY 36
#  define RSFT_KEY 258
#  define RCTRL_KEY 269
#  define ROPT_KEY 262
#  define RCMD_KEY 260
#  define FN_KEY 279
#  define RDEL_KEY 117
#  define HOME_KEY 115
#  define END_KEY 119
#  define PUP_KEY 116
#  define PDOWN_KEY 121
#  define CLR_KEY 71
# endif

#endif
