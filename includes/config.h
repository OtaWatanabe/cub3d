/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knamba <knamba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:02:04 by knamba            #+#    #+#             */
/*   Updated: 2025/02/16 14:02:05 by knamba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

// 画面サイズ
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768

// Linux環境のキーコード
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
# define MASK_KEY_PRESS 1L
# define MASK_KEY_RELEASE 2L

// マウス感度
# define MOUSE_SENSITIVITY 0.001
// プレイヤーの移動速度
# define MOVE_SPEED 0.02
// プレイヤーの回転速度
# define ROT_SPEED -0.01
// プレイヤーの衝突判定用円の半径
# define COLLISION_RADIUS 0.011
# define EPSILON 0.01
// ミニマップの設定
# define MINIMAP_OFFSET_X 10
# define MINIMAP_OFFSET_Y 10
# define ARROW_LEN 10.0
# define MINIMAP_MAX_WIDTH 100
# define MINIMAP_MAX_HEIGHT 100

#endif