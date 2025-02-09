#ifndef CONFIG_H
# define CONFIG_H

// 画面サイズ
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768

// Linux環境のキーコード
// (X11/keysym.hなどから参照)
# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

// MinilibXのKeyPress / KeyRelease イベント
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3

// マスク (KeyPressMask, KeyReleaseMask)
# define MASK_KEY_PRESS (1L << 0)
# define MASK_KEY_RELEASE (1L << 1)

# define MAP_WIDTH 100
# define MAP_HEIGHT 50

# define MOVE_SPEED 0.01 // 前後左右の移動速度
# define ROT_SPEED -0.01 // 回転速度

# define MINIMAP_OFFSET_X 10
# define MINIMAP_OFFSET_Y 10
# define ARROW_LEN 10.0
# define MINIMAP_MAX_WIDTH 300
# define MINIMAP_MAX_HEIGHT 300

# define MOUSE_SENSITIVITY 0.001

#endif