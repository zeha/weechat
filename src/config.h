/*
 * Copyright (c) 2003 by FlashCode <flashcode@flashtux.org>
 *                       Bounga <bounga@altern.org>
 *                       Xahlexx <xahlexx@tuxisland.org>
 * See README for License detail.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */


#ifndef __WEECHAT_CONFIG_H
#define __WEECHAT_CONFIG_H 1

#define WEECHAT_CONFIG_NAME "weechat.rc"

#define CONFIG_SECTION_NONE    -1
#define CONFIG_SECTION_LOOK    0
#define CONFIG_SECTION_COLORS  1
#define CONFIG_SECTION_HISTORY 2
#define CONFIG_SECTION_LOG     3
#define CONFIG_SECTION_DCC     4
#define CONFIG_SECTION_PROXY   5
#define CONFIG_SECTION_SERVER  6
#define CONFIG_NUMBER_SECTIONS 7

#define OPTION_TYPE_BOOLEAN         1   /* values: on/off                   */
#define OPTION_TYPE_INT             2   /* values: from min to max          */
#define OPTION_TYPE_INT_WITH_STRING 3   /* values: one from **array_values  */
#define OPTION_TYPE_COLOR           4   /* values: a color name             */
#define OPTION_TYPE_STRING          5   /* values: any string, may be empty */

#define BOOL_FALSE 0
#define BOOL_TRUE  1

#define CFG_LOOK_NICKLIST_LEFT   0
#define CFG_LOOK_NICKLIST_RIGHT  1
#define CFG_LOOK_NICKLIST_TOP    2
#define CFG_LOOK_NICKLIST_BOTTOM 3

typedef struct t_config_section t_config_section;

struct t_config_section
{
    int section_number;
    char *section_name;
};

typedef struct t_config_option t_config_option;

struct t_config_option
{
    char *option_name;
    char *short_description;
    char *long_description;
    int option_type;
    int min, max;
    int default_int;
    char *default_string;
    char **array_values;
    int *ptr_int;
    char **ptr_string;
    int (*handler_change)(int *, char **);
};

extern int cfg_look_startup_logo;
extern int cfg_look_startup_version;
extern char *cfg_look_weechat_slogan;
extern int cfg_look_color_nicks;
extern int cfg_look_color_actions;
extern int cfg_look_remove_colors_from_msgs;
extern int cfg_look_nicklist;
extern int cfg_look_nicklist_position;
extern int cfg_look_nicklist_min_size;
extern int cfg_look_nicklist_max_size;
extern int cfg_look_nickmode;
extern int cfg_look_nickmode_empty;
extern char *cfg_look_no_nickname;
extern char *cfg_look_completor;

extern int cfg_col_title;
extern int cfg_col_title_bg;
extern int cfg_col_chat;
extern int cfg_col_chat_time;
extern int cfg_col_chat_time_sep;
extern int cfg_col_chat_prefix1;
extern int cfg_col_chat_prefix2;
extern int cfg_col_chat_nick;
extern int cfg_col_chat_host;
extern int cfg_col_chat_channel;
extern int cfg_col_chat_dark;
extern int cfg_col_chat_bg;
extern int cfg_col_status;
extern int cfg_col_status_active;
extern int cfg_col_status_data_msg;
extern int cfg_col_status_data_other;
extern int cfg_col_status_more;
extern int cfg_col_status_bg;
extern int cfg_col_input;
extern int cfg_col_input_channel;
extern int cfg_col_input_nick;
extern int cfg_col_input_bg;
extern int cfg_col_nick;
extern int cfg_col_nick_op;
extern int cfg_col_nick_halfop;
extern int cfg_col_nick_voice;
extern int cfg_col_nick_sep;
extern int cfg_col_nick_self;
extern int cfg_col_nick_private;
extern int cfg_col_nick_bg;

extern int cfg_history_max_lines;
extern int cfg_history_max_commands;

extern int cfg_log_auto_channels;
extern int cfg_log_auto_private;
extern char *cfg_log_path;
extern char *cfg_log_name;
extern char *cfg_log_timestamp;
extern char *cfg_log_start_string;
extern char *cfg_log_end_string;

extern int cfg_dcc_auto_accept_files;
extern int cfg_dcc_auto_accept_max_size;
extern int cfg_dcc_auto_accept_chats;
extern int cfg_dcc_timeout;
extern char *cfg_dcc_download_path;
extern char *cfg_dcc_upload_path;
extern int cfg_dcc_auto_rename;
extern int cfg_dcc_auto_resume;

extern int cfg_proxy_use;
extern char *cfg_proxy_address;
extern int cfg_proxy_port;
extern char *cfg_proxy_password;

extern t_config_section config_sections [CONFIG_NUMBER_SECTIONS];
extern t_config_option * weechat_options [CONFIG_NUMBER_SECTIONS];

extern int config_read ();
extern int config_create_default ();
extern int config_write ();

#endif /* config.h */
