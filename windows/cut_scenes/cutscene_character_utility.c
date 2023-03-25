/*
** EPITECH PROJECT, 2022
** MyRPG
** File description:
** cutscene_character_utility
*/

#include "cutscene.h"

static sfRectangleShape *create_char_npc(const char *filepath);
static sfRectangleShape *create_char_player(const char *filepath);

const char *char_array[30] = {
    "asset/characters/Katashi1.png",
    "asset/characters/Katashi2.png",
    "asset/characters/Katashi3.png",
    "asset/characters/Katashi4.png",
    "asset/characters/Katashi5.png",
    "asset/characters/Arkhen.png",
    "asset/characters/Demon_A.png",
    "asset/characters/Demon_B.png",
    "asset/characters/enemy_BF_U.png",
    "asset/characters/enemy_BM_U.png",
    "asset/characters/enemy_MnF_U.png",
    "asset/characters/enemy_MnM_U.png",
    "asset/characters/enemy_SF_U.png",
    "asset/characters/enemy_SM_U.png",
    "asset/characters/Hogo-Sama.png",
    "asset/characters/Iga.png",
    "asset/characters/koga.png",
    "asset/characters/Lame.png",
    "asset/characters/NPC_A.png",
    "asset/characters/NPC_C.png",
    "asset/characters/NPC_E.png",
    "asset/characters/NPC_L.png",
    "asset/characters/NPC_Ra.png",
    "asset/characters/NPC_Rb.png",
    "asset/characters/NPC_Rc.png",
    "asset/characters/NPC_Rd.png",
    "asset/characters/NPC_Re.png",
    "asset/characters/NPC_Rf.png",
    "asset/characters/Ombre.png",
    NULL
};

const char *char_name_array[30] = {
    "Katashi",
    "Katashi",
    "Katashi",
    "Katashi",
    "Katashi",
    "Arkhen",
    "Demon A",
    "Demon B",
    "Bully",
    "Bully",
    "Missing Nin",
    "Missing Nin",
    "Sila'a Nin",
    "Sila'a Nin",
    "Hogo-Sama",
    "Iga",
    "Koga",
    "Lame",
    "Artia",
    "Colin'ia",
    "Est'eon",
    "Lu'tra ",
    "Sem'na",
    "Samn'io",
    "Eli",
    "Seta",
    "Ta'et",
    "Stem'io",
    "Ombre",
    NULL
};

void print_character(int id, sfRenderWindow *win, sfRectangleShape **sprite)
{
    sfRenderWindow_drawRectangleShape(win, sprite[id], NULL);
}

void print_character_name(int id, sfRenderWindow *win,  sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos;

    pos.x = 130;
    pos.y = 830;
    sfText_setString(text, char_name_array[id]);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 30);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(win, text, NULL);
}

sfRectangleShape **init_character(void)
{
    int counter = 0;
    sfRectangleShape **sprite = malloc(sizeof(*sprite) * 30);

    while (char_array[counter] != NULL) {
        if (counter < 5)
            sprite[counter] = create_char_player(char_array[counter]);
        else {
            sprite[counter] = create_char_npc(char_array[counter]);
        }
        counter++;
    }
    return (sprite);
}

static sfRectangleShape *create_char_npc(const char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    pos.x = 1540;
    pos.y = 500;
    size.x = 300;
    size.y = 300;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return (sprite);
}

static sfRectangleShape *create_char_player(const char *filepath)
{
    sfVector2f pos;
    sfVector2f size;
    sfVector2f scale;
    sfRectangleShape *sprite = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    scale.x = -1;
    scale.y = 1;
    pos.x = 340;
    pos.y = 500;
    size.x = 300;
    size.y = 300;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    sfRectangleShape_setScale(sprite, scale);
    return (sprite);
}
