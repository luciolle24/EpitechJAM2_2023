##
## EPITECH PROJECT, 2021
## task02
## File description:
## Makefile
##

SRC = initialization/main.c\
	  windows/menu_file/menu.c\
	  windows/menu_file/menu_play.c\
	  windows/menu_file/menu_info.c\
	  windows/menu_file/menu_quit.c\
	  windows/menu_file/menu_event.c\
	  windows/menu_file/menu_destroy.c\
	  windows/menu_file/menu_function.c\
	  windows/menu_file/menu_settings.c\
	  windows/menu_file/menu_display_info.c\
	  windows/menu_file/menu_display_info_2.c\
	  windows/choose_game_save/event.c\
	  windows/choose_game_save/choose_save.c\
	  windows/choose_game_save/destroy_choose_save.c\
	  windows/choose_game_save/def_choose_save.c\
	  windows/choose_game_save/first_save_sprite.c\
	  windows/choose_game_save/second_save_sprite.c\
	  windows/choose_game_save/third_save_sprite.c\
	  windows/choose_game_save/def_simple_background.c\
	  windows/choose_game_save/event_select_save.c\
	  windows/choose_game_save/quit_button.c\
	  windows/setting/attack.c\
	  windows/setting/move_up.c\
	  windows/setting/move_down.c\
	  windows/setting/move_left.c\
	  windows/setting/move_right.c\
	  windows/setting/def_settings.c\
	  windows/setting/interact.c\
	  windows/setting/settings.c\
	  windows/setting/quit.c\
	  windows/setting/display.c\
	  windows/setting/event.c\
	  generator/map_generator.c\
	  generator/generate_river.c\
	  generator/generate_forest.c\
	  generator/generate_cities.c\
	  generator/generate_bridge.c\
	  generator/split_map.c\
	  generator/restore_map.c\
	  generator/generate_bridge_utils.c\
	  windows/setting/destroy.c\
	  windows/setting/key_binding.c\
	  windows/setting/key_binding_utility.c\
	  windows/setting/select_key_to_bind.c\
	  windows/setting/select_key_to_bind_2.c\
	  windows/setting/def_slider.c\
	  windows/setting/back_setting.c\
	  windows/setting/slider_event.c\
      windows/cut_scenes/cutscene_utility.c\
	  windows/cut_scenes/cutscene_utility2.c\
	  windows/cut_scenes/cutscene_show.c\
	  windows/cut_scenes/cutscene_character_utility.c\
	  windows/cut_scenes/cutscene.c\
	  game/run_game.c\
	  game/time.c\
	  game/init_game_data.c\
	  game/get_map.c\
	  game/display.c\
	  game/init_images.c\
	  game/destroy_game_data.c\
	  game/get_texture.c\
	  game/get_texture_nbr.c\
	  game/destroy_map_tiles.c\
	  game/get_texture_bridge_name.c\
	  game/events/events.c\
	  game/monsters/init_monsters.c\
	  game/monsters/update_monsters.c\
	  game/player/init_player.c\
	  game/player/update_player.c\
	  game/player/anim_player.c\
	  game/player/destroy_player.c\
	  game/player/collider/check_collider.c\
	  game/characters/init_characters.c\
	  game/characters/update_characters.c\
	  game/npc/display.c\
	  game/npc/def_npc.c\
	  game/pause/event.c\
	  game/pause/pause.c\
	  game/pause/display.c\
	  game/pause/def_sprite.c\
	  game/pause/select_button.c\
	  game/pause/destroy.c\
	  game/pause/init_sprite.c\
	  utils/list.c\
	  utils/clock_utility.c\
	  utils/event_hanlder.c\
	  game_engine/inventory/create_inventory.c\
	  game_engine/inventory/inventory.c\
	  game_engine/inventory/create_items.c\
	  save_actions/fill_datas.c\
	  save_actions/fill_save.c\
	  save_actions/start_save.c\
	  save_actions/fill_utility.c\


OBJ = ${SRC:.c=.o}
LIB_CMD = -L./lib/my/ -lmy
INCLUDE_CMD = -I./include/
NAME = my_rpg

all: compile_lib
	@echo -e "\e[95m\nCompilings project"
	@make ${OBJ} -s
	@echo -e "\e[95m\nBuilding project\e[96m"
	@make ${NAME} -s
	@echo -e "\e[95m\nFinished Everything\e[0m"

${NAME}: ${OBJ}
	@echo -e "gcc -o ${NAME} ${OBJ} ${LIB_CMD} -lcsfml-window \
	-lcsfml-graphics -lcsfml-system -lcsfml-audio\e[0m"
	@gcc -o ${NAME} ${OBJ} ${LIB_CMD} -lcsfml-window -lcsfml-graphics \
	-lcsfml-system -lcsfml-audio

%.o: %.c
	@echo -e -n "\e[96m  - $<\e[0m\n"
	@gcc -c ${INCLUDE_CMD} $< -o $@ -g3

compile_lib:
	@cd lib/my && make -s && cd ../../

clean:
	@echo -e "\e[95mOn project"
	@rm -f ${OBJ}
	@echo -e "\e[96m  - deleting *.o\e[0m"

fclean: clean
	@rm -f ${NAME}
	@echo -e "\e[96m  - deleting ${NAME}\n\e[0m"
	@cd lib/my && make fclean -s && cd ../../

re: fclean
	@echo -e "\e[96m,--.   ,--.         ,------. ,------.  ,----."
	@echo -e "\e[96m|   \`.'   |,--. ,--.|  .--. '|  .--. ''  .-."
	@echo -e "\e[96m|  |'.'|  | \  '  / |  '--'.'|  '--' ||  | .---."
	@echo -e "\e[96m|  |   |  |  \   '  |  |\  \ |  | --' '  '--'  |"
	@echo -e "\e[96m\`--'   \`--'.-'  /  \`--'  '--''--'      \`------'"
	@echo -e "\e[96m          \`---'                            "
	@make all -s
