/*
    License for Butano:

    Copyright (c) 2020-2022 Gustavo Valiente gustavo.valiente@protonmail.com
    zlib License, see LICENSE file.
*/

// Butano libraries
#include "bn_core.h" // Core libraries.
#include "bn_log.h"
#include "bn_music.h"
#include "bn_music_actions.h"
#include "bn_music_items.h"
#include "bn_sound_items.h"
#include "bn_sram.h"
#include "bn_math.h"
#include "bn_string.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_random.h"
#include "bn_regular_bg_ptr.h"
#include "bn_sprite_text_generator.h"
#include "bn_sprite_animate_actions.h"
#include "bn_sprite_palette_ptr.h"
#include "common_info.h"
#include "common_variable_8x8_sprite_font.h"

#include <unistd.h>
#include "bn_random.h"
#include <vector>
#include "bn_sprite_items_main_hero.h"
#include "bn_sprite_items_key.h"
#include "bn_sprite_items_gem.h"
#include "bn_sprite_items_main_hero_2.h"
#include "bn_sprite_items_zombie.h"
#include "bn_sprite_items_bomb.h"
#include "bn_sprite_items_explosion.h"
#include "bn_regular_bg_items_bg.h"
#include "bn_regular_bg_items_title_screen.h"
#include "bn_regular_bg_items_bg2.h"
#include "bn_regular_bg_items_test.h"
#include "bn_regular_bg_items_combined_vertical.h"
#include "bn_regular_bg_items_fullbg.h"
#include "bn_sprite_items_ghost.h"
#include "bn_sprite_items_powerup.h"
#include "bn_sprite_items_gem2.h"

#define rows 24
#define columns 30

#define rows2 21
#define columns2 21



bool is_collision(int player_x, int player_y, int gem_x, int gem_y)
    {
        const int collision_threshold = 8; // 8x8 pixel tiles
        return abs(player_x - gem_x) < collision_threshold && abs(player_y - gem_y) < collision_threshold;
    }

void show_temporary_text(bn::sprite_text_generator& text_generator, const bn::fixed_point& position, const bn::string<48>& message, int duration_frames) {
    // Create a temporary vector to store text sprites
    bn::vector<bn::sprite_ptr, 48> temp_text_sprites;
    text_generator.generate(position.x(), position.y(), message, temp_text_sprites);

    // Keep the text visible for the specified duration
    for (int i = 0; i < duration_frames; i++) {
        bn::core::update(); // Update the game for one frame
    }

    // Clear the temporary text
    temp_text_sprites.clear();
}

void reset(){
    bn::core::reset();
}


int main()
{
    // Initialization
    bn::core::init();


    


    int collisionMap[rows][columns] = {

    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1,0,1},
    {1,0,1,1,1,1,1,1,0,1,0,1,1,0,1,0,1,0,1,1,1,0,1,0,0,1,0,1,0,1},
    {1,0,1,0,0,0,0,0,0,1,0,1,1,0,1,1,1,0,1,0,1,0,0,0,1,1,0,1,0,1},
    {1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,1,0,1,1,1,0,1,1,0,1,1,1,0,1,0,1,0,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,1,1,1,1,2,1},
    {1,0,1,0,0,0,1,0,0,1,1,1,1,0,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,1},
    {1,0,1,0,1,1,1,1,0,0,0,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,1,1,0,1},
    {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,1},
    {1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,0,1,1,1,0,0,1,0,1,1,1},
    {1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,1,0,1,1,0,0,1,0,0,1,1,0,0,0,1},
    {1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1,0,0,0,1,1,1,0,1,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,4,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    };

    int playerX = 2;
    int playerY = 2;

    int collisionMap2[rows2][columns2] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,0,1,0,1},
        {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1},
        {1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,1,0,1},
        {1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1},
        {1,1,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,8,0,0,0,0,1},
        {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1},
        {1,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1},
        {1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,1},
        {1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,0,1,0,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1},
        {1,1,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,1,1,0,1},
        {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,1},
        {1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,9,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,90,1}
         
    };
    
    int playerX2 = 19;
    int playerY2 = 1;
    
    //Title Screen
    bn::regular_bg_ptr title_screen = bn::regular_bg_items::title_screen.create_bg(6, 40);
    

    // Variables
    int score = 0;               // Gem score
    int score2 = 0;
    int allowscore2 = 0;
    int health = 3;
    int allow = 0;               // Allowed to open door or not (1 or higher yes)    
    int allowghost = 0;
    int key_obtained = 0;        // Secret key to open second (final) door
    int key2_obtained = 0;
    int door_unlocked = 0;       // Notice players that 20 gems collected
    int door2_unlocked = 0;
    int level = 0;
    int allowZ = 0;
    int random4 = 0;
    int random5 = 0;
    int temp = 0;
    bn::random rng;
    int cooldown = 60;
    int cooldown2 = 20;
    int cooldown3 = 60;
    int direction = 0;
    int winner = 0;

    int options0[] = {2,3};
    int options1[] = {0,1};


    int random_index = rng.get_int(2);



    // Title screen text generator setup
    bn::sprite_text_generator text_generator(common::variable_8x8_sprite_font);
    bn::vector<bn::sprite_ptr, 16> text_sprites;
    text_generator.generate(-53, 65, "(Press START to start)", text_sprites);
   
    
    while (!bn::keypad::start_pressed())
    {
        bn::core::update();
    }

    //main hero sprite
    bn::sprite_ptr main_hero = bn::sprite_items::main_hero.create_sprite(-102,-74);

    // Zombies/ghost

    bn::sprite_ptr zombie1 = bn::sprite_items::zombie.create_sprite(-54,-58);
    bn::sprite_ptr zombie2 = bn::sprite_items::zombie.create_sprite(-54,-34);
    bn::sprite_ptr zombie3 = bn::sprite_items::zombie.create_sprite(90,6);

    bn::sprite_ptr zombie4 = bn::sprite_items::zombie.create_sprite(-46,42);
    bn::sprite_ptr zombie5 = bn::sprite_items::zombie.create_sprite(-46,-22);

    bn::sprite_ptr ghost1 = bn::sprite_items::ghost.create_sprite(-58,-75 );

    ghost1.set_visible(false);

    ghost1.set_z_order(0);

    zombie4.set_visible(false);
    zombie5.set_visible(false);
    

    zombie4.set_z_order(0);
    zombie5.set_z_order(0);

    int zombieX4 = 9;
    int zombieY4 = 15;

    int zombieX5 = 9;
    int zombieY5 = 7;

    bool going_up = true;
    bool going_left = true;
    bool going_up_z3 = true;

    const int zombie1_top_wall_y = -58;
    const int zombie1_bottom_wall_y = 38;

    const int zombie2_left_wall_x = -58;
    const int zombie2_right_wall_x = 14;

    const int zombie3_top_wall_y = 6;
    const int zombie3_bottom_wall_y = 62;
    

    bn::sprite_ptr power1 = bn::sprite_items::powerup.create_sprite(-22,-70);
    bn::sprite_ptr power2 = bn::sprite_items::powerup.create_sprite(-46,74);

    power1.set_visible(false);
    power2.set_visible(false);
    
    
    //Gem Struct
    struct Gem {
        bn::sprite_ptr sprite;
        bool collected;
    };

    std::vector<Gem> gems = {
    //gems sprites (20 total)
        {bn::sprite_items::gem.create_sprite(-110,-58),false},
        {bn::sprite_items::gem.create_sprite(-94,-42), false},
        {bn::sprite_items::gem.create_sprite(-46,62), false},
        {bn::sprite_items::gem.create_sprite(-54,-58), false},

        {bn::sprite_items::gem.create_sprite(-86,-10), false},
        {bn::sprite_items::gem.create_sprite(-78,30), false},
        {bn::sprite_items::gem.create_sprite(-46,46), false},
        {bn::sprite_items::gem.create_sprite(-30,38), false},
        {bn::sprite_items::gem.create_sprite(-6,54), false},
        {bn::sprite_items::gem.create_sprite(2,30), false},
        {bn::sprite_items::gem.create_sprite(26,62), false},
        {bn::sprite_items::gem.create_sprite(34,-42), false},
        {bn::sprite_items::gem.create_sprite(58,-2), false},
        {bn::sprite_items::gem.create_sprite(66,-26), false},
        {bn::sprite_items::gem.create_sprite(2,-50), false},
        {bn::sprite_items::gem.create_sprite(-30,-58), false},
        {bn::sprite_items::gem.create_sprite(-30,-2), false},
        {bn::sprite_items::gem.create_sprite(-110,38), false},
        {bn::sprite_items::gem.create_sprite(98,30), false},
        {bn::sprite_items::gem.create_sprite(74,38), false},
    };



    
    // Gem 2 structure
    struct Gem2 {
            bn::sprite_ptr sprite;
            bool collected;
    };
    
     std::vector<Gem2> gems2 = {
        //gems2 sprites (20 total)
     {bn::sprite_items::gem2.create_sprite(-110,-70), false},
     {bn::sprite_items::gem2.create_sprite(18,-70), false},
     {bn::sprite_items::gem2.create_sprite(-110,74), false},
     {bn::sprite_items::gem2.create_sprite(18,74), false},
     {bn::sprite_items::gem2.create_sprite(-110,-54), false},
     {bn::sprite_items::gem2.create_sprite(18,-54), false},
     {bn::sprite_items::gem2.create_sprite(-110,-38), false},
     {bn::sprite_items::gem2.create_sprite(18,-38), false},
     {bn::sprite_items::gem2.create_sprite(-54,-70), false},
     {bn::sprite_items::gem2.create_sprite(-38,-70), false},
     {bn::sprite_items::gem2.create_sprite(-70,-22), false},
     {bn::sprite_items::gem2.create_sprite(-22,-22), false},
     {bn::sprite_items::gem2.create_sprite(-110,26), false},
     {bn::sprite_items::gem2.create_sprite(18,26), false},
     {bn::sprite_items::gem2.create_sprite(-54,26), false},
     {bn::sprite_items::gem2.create_sprite(-38,26), false},
     {bn::sprite_items::gem2.create_sprite(10,50), false},
     {bn::sprite_items::gem2.create_sprite(-102,50), false},
     {bn::sprite_items::gem2.create_sprite(-54,-38), false},
     {bn::sprite_items::gem2.create_sprite(-38,-38), false},
     {bn::sprite_items::gem2.create_sprite(-62,74), false},
     {bn::sprite_items::gem2.create_sprite(-30,74), false},
     {bn::sprite_items::gem2.create_sprite(-78,42), false},
     {bn::sprite_items::gem2.create_sprite(-14,42), false},
     };
    

    struct Key {
        bn::sprite_ptr sprite;
        bool collected;
    };

    std::vector<Key> keys = {
        {bn::sprite_items::key.create_sprite(106,-58), false},
    };
   

    struct Bomb {
        bn::sprite_ptr sprite;
        bool collected;
    };

    std::vector<Bomb> bombs = {
    //bombs sprites (5 total)
        {bn::sprite_items::bomb.create_sprite(-110,-10),false},
        {bn::sprite_items::bomb.create_sprite(-62,-18), false},
        {bn::sprite_items::bomb.create_sprite(34,22), false},
        {bn::sprite_items::bomb.create_sprite(18,-10), false},
        {bn::sprite_items::bomb.create_sprite(-62,-10), false}

    };

    bn::regular_bg_ptr full = bn::regular_bg_items::fullbg.create_bg(6, 169);

    // Main game loop
    while (true)
    {
        text_sprites.clear();
        title_screen.set_visible(false);
    // Create the maze background.
        


        
    if (level == 0){ 
        bn::string<48> txt_score = "Gems collected: " + bn::to_string<32>(score);
        text_generator.generate(15, -75, txt_score, text_sprites);


        bn::string<48> txt_health = "Lives: " + bn::to_string<32>(health);
        text_generator.generate(-50, -75, txt_health, text_sprites);
    }

        


        if (bn::keypad::down_pressed() && (collisionMap[playerY + 1][playerX] == 0) && (level == 0)){
            playerY++;
            main_hero.set_y(main_hero.y() + 8);
        }

        else 

        if (bn::keypad::up_pressed() && (collisionMap[playerY - 1][playerX] == 0) && (level == 0)){
            playerY--;
            main_hero.set_y(main_hero.y() - 8);
        }

        if (bn::keypad::right_pressed() && (collisionMap[playerY][playerX+1] == 0) && (level == 0)){
            playerX++;
            main_hero.set_x(main_hero.x() + 8);
        }

        if (bn::keypad::left_pressed() && (collisionMap[playerY][playerX - 1] == 0) && (level == 0)){
            playerX--;
            main_hero.set_x(main_hero.x() - 8);
        }

        if ((score == 20) && (door_unlocked == 0) && (level == 0)){
            bn::string<64> message3 = "A door has been unlocked";
            show_temporary_text(text_generator, bn::fixed_point(-60, 65), message3, 60);
            allow = 1;
            door_unlocked = 1;
        } 

        for(Key& key : keys)
        {
        if(!key.collected && is_collision(main_hero.x().integer(), main_hero.y().integer(), key.sprite.x().integer(), key.sprite.y().integer()) && (level == 0))
        {
                key.collected = true;          // Mark as collected
                key.sprite.set_visible(false); // Hide the key
                key_obtained++;
                bn::string<64> message = "Key obtained";
                show_temporary_text(text_generator, bn::fixed_point(-32, -10), message, 60);
                bn::sound_items::diamond.play(0.3); // Play a sound
        }
    }
        


        if (bn::keypad::up_pressed() && (collisionMap[ playerY - 1][playerX] > 1) && (level == 0)){
            if (allow == 1){
                bn::string<64> message = "Door unlocked.";
                bn::sound_items::door_open.play(0.5);
                show_temporary_text(text_generator, bn::fixed_point(-38, 65), message, 60);
                collisionMap[playerY - 1][playerX] = 0;
            }
            else{
            bn::string<64> message = "This door has not been unlocked yet.";
            show_temporary_text(text_generator, bn::fixed_point(-100, 65), message, 60);
            }

        }  

        if (bn::keypad::down_pressed() && (collisionMap[playerY + 1][playerX] == 3) && (level == 0)){
            if (key_obtained == 0){
                bn::string<64> message = "This door has not been unlocked yet.";
                show_temporary_text(text_generator, bn::fixed_point(-100, 65), message, 60);
            }
            else{
                bn::string<64> message = "Door unlocked.";
                bn::sound_items::door_open.play(0.5);
                show_temporary_text(text_generator, bn::fixed_point(-38, 65), message, 60);
                collisionMap[playerY + 1][playerX] = 0; 

            }
        }

        if (collisionMap[playerY + 1][playerX] == 4){
            collisionMap[playerY + 1][playerX] = 0;
            score++;
        }

       for(Bomb& bomb : bombs)
        {
        if(!bomb.collected && is_collision(main_hero.x().integer(), main_hero.y().integer(), bomb.sprite.x().integer(), bomb.sprite.y().integer()) && (level == 0))
        {       
                bn::sound_items::explosion.play(0.5);
                bn::sprite_ptr explosion = bn::sprite_items::explosion.create_sprite(main_hero.x(),main_hero.y());
                bn::string<64> message4 = "Avoid the bombs!";
                show_temporary_text(text_generator, bn::fixed_point(-40, 65), message4, 60);
                main_hero.set_x(main_hero.x() = -102);
                main_hero.set_y(main_hero.y() = -74);
                playerX = 2;
                playerY = 2;   
                health = health - 1;                   
                
        }
    }
        //zombie 1 movement
        if (going_up){
            zombie1.set_y(zombie1.y() - 0.8);
        }
        else{
            zombie1.set_y(zombie1.y() + 0.8);
        }
      
        if (zombie1.y() <= zombie1_top_wall_y){
            going_up = false;
        }

        else if (zombie1.y() >= zombie1_bottom_wall_y){
            going_up = true;
        }

        //zombie 2 movement
        if (going_left){
            zombie2.set_x(zombie2.x() - 0.5);
        }
        else{
            zombie2.set_x(zombie2.x() + 0.5);
        }
      
        if (zombie2.x() <= zombie2_left_wall_x){
            going_left = false;
        }

        else if (zombie2.x() >= zombie2_right_wall_x){
            going_left = true;
        }

        
        //zombie 3 movement
        if (going_up_z3){
            zombie3.set_y(zombie3.y() - 0.3);
        }
        else{
            zombie3.set_y(zombie3.y() + 0.3);
        }
      
        if (zombie3.y() <= zombie3_top_wall_y){
            going_up_z3 = false;
        }

        else if (zombie3.y() >= zombie3_bottom_wall_y){
            going_up_z3 = true;
        }


        if (is_collision(main_hero.x().integer(),main_hero.y().integer(),zombie1.x().integer(),zombie1.y().integer()) && (level == 0)){
                bn::string<64> message5 = "Avoid the zombies!";
                show_temporary_text(text_generator, bn::fixed_point(-40, 65), message5, 60);
                main_hero.set_x(main_hero.x() = -102);
                main_hero.set_y(main_hero.y() = -74);
                playerX = 2;
                playerY = 2; 
                health = health - 1;
        }

        if (is_collision(main_hero.x().integer(),main_hero.y().integer(),zombie2.x().integer(),zombie2.y().integer()) && (level == 0)){
                bn::string<64> message5 = "Avoid the zombies!";
                show_temporary_text(text_generator, bn::fixed_point(-40, 65), message5, 60);
                main_hero.set_x(main_hero.x() = -102);
                main_hero.set_y(main_hero.y() = -74);
                playerX = 2;
                playerY = 2; 
                health = health - 1;
        }

        if (is_collision(main_hero.x().integer(),main_hero.y().integer(),zombie3.x().integer(),zombie3.y().integer()) && (level == 0)){
                bn::string<64> message5 = "Avoid the zombies!";
                show_temporary_text(text_generator, bn::fixed_point(-40, 65), message5, 60);
                main_hero.set_x(main_hero.x() = -102);
                main_hero.set_y(main_hero.y() = -74);
                playerX = 2;
                playerY = 2; 
                health = health - 1;
        }


        for(Gem& gem : gems)
        {
        if(!gem.collected && is_collision(main_hero.x().integer(), main_hero.y().integer(), gem.sprite.x().integer(), gem.sprite.y().integer()))
        {
                gem.collected = true;          // Mark as collected
                gem.sprite.set_visible(false); // Hide the gem
                score++;                      // Increase the score
                bn::sound_items::diamond.play(0.3); // Play a sound
        }
    }


    while (health == 0){
        bn::string<64> message5 = "You Lose!";
        show_temporary_text(text_generator, bn::fixed_point(-40, 65), message5, 60);
    }

   //////////////////
   //          LEVEL 2 Properties


    if (score == 21){
        level = 3;
        full.set_y(-82);
        score++;

        allowscore2 = 1;

        main_hero.set_x(34);
        main_hero.set_y(-70);
        score++;
        zombie1.set_visible(false);
        zombie2.set_visible(false);
        zombie3.set_visible(false);

        zombie4.set_visible(true);
        zombie5.set_visible(true);

        ghost1.set_x(-46);
        ghost1.set_y(-54);

        ghost1.set_visible(true);
        
        allowZ = 1;
        
        

        power1.set_visible(true);
        power2.set_visible(true);
        
        random4 = rng.get_unbiased_int(4);
        random5 = rng.get_unbiased_int(4);
        health = 3;

        
    }


    if (level == 3){ 
        bn::string<48> txt_score = "Gems: " + bn::to_string<32>(score2);
        text_generator.generate(55, -30, txt_score, text_sprites);


        bn::string<48> txt_health = "Lives: " + bn::to_string<32>(health);
        text_generator.generate(50, 20, txt_health, text_sprites);
    }


    for(Bomb& bomb : bombs){
        if(level == 3){
          bomb.sprite.set_visible(false);
        }
    }


//////////////////////////////
////////    END GAME PROPERTIES


if (score2 == 24){
    score2 = 25;
    key2_obtained = 1;  
    door2_unlocked = 1;
    bn::string<64> message12 = "Key obtained";
    show_temporary_text(text_generator, bn::fixed_point(-55, 65), message12, 60);  
}


if (bn::keypad::down_pressed() && (collisionMap2[playerY2 + 1][playerX2] == 90)){
    winner = 1;        
    }

while (winner == 1){
    bn::string<64> message12 = "You Win!";
    show_temporary_text(text_generator, bn::fixed_point(-55, 65), message12, 60);
}


///////////////////
//  GEM 2 properties




for(Gem2& gem2 : gems2)
{
if(!gem2.collected && is_collision(main_hero.x().integer(), main_hero.y().integer(), gem2.sprite.x().integer(), gem2.sprite.y().integer()) && level == 3)
{
        gem2.collected = true;          // Mark as collected
        gem2.sprite.set_visible(false); // Hide the gem
        score2++;                      // Increase the score
        bn::sound_items::diamond.play(0.3); // Play a sound
}
}

for(Gem2& gem2 : gems2)
{
if(level == 0)
{
    gem2.sprite.set_visible(false); // Hide the gem
        
}
}

for(Gem2& gem2 : gems2)
{
if(!gem2.collected && (level == 3))
{
    gem2.sprite.set_visible(true); // show the gem
    
        
}
}

for(Gem2& gem2 : gems2)
{
    gem2.sprite.set_z_order(1);
}


/////////////////////////////////



    if (bn::keypad::down_pressed() && (collisionMap2[playerY2 + 1][playerX2] == 9)){
        if (door2_unlocked == 0){
            bn::string<64> message12 = "This door has not been unlocked yet.";
            show_temporary_text(text_generator, bn::fixed_point(-95, 65), message12, 60);
        }
        else{
            bn::string<64> message15 = "Door unlocked.";
            bn::sound_items::door_open.play(0.5);
            show_temporary_text(text_generator, bn::fixed_point(-38, 65), message15, 60);
            collisionMap2[playerY2 + 1][playerX2] = 0; 

        }
    }
    if (bn::keypad::down_pressed() && (collisionMap2[playerY2 + 1][playerX2] == 0) && (level == 3)){
        playerY2++;
        main_hero.set_y(main_hero.y() + 8);
    }
 

    if (bn::keypad::up_pressed() && (collisionMap2[playerY2 - 1][playerX2] == 0) && (level == 3)){
        playerY2--;
        main_hero.set_y(main_hero.y() - 8);
    }

    if (bn::keypad::right_pressed() && ((collisionMap2[playerY2][playerX2+1] == (0)) || (collisionMap2[playerY2][playerX2+1] == (8))) && (level == 3)){
        if (collisionMap2[playerY2][playerX2+1] == (8)){
        allowghost = 0;
        ghost1.set_x(-46);
        ghost1.set_y(-54);
        }
        playerX2++;
        main_hero.set_x(main_hero.x() + 8);
    }


    
    if (bn::keypad::left_pressed() && ((collisionMap2[playerY2][playerX2 - 1] == (0)) || (collisionMap2[playerY2][playerX2 - 1] == (8))) && (level == 3)){
        if (collisionMap2[playerY2][playerX2 - 1] == (8)){ 
        allowghost = 1;
        }
        playerX2--;
        main_hero.set_x(main_hero.x() - 8);
    }



//////////////////////
////// Powerup condition
    if ((main_hero.x().integer() == power1.x().integer()) && (main_hero.y().integer() == power1.y().integer())){
        cooldown3 = 300;
        power1.set_y(power1.y() = 127);
        power1.set_visible(false);
    }

    if ((main_hero.x().integer() == power2.x().integer()) && (main_hero.y().integer() == power2.y().integer())){
        cooldown3 = 300;
        power2.set_y(power2.y() = 127);
        power2.set_visible(false);
    }

//////////////////////////////////
//     GHOST MOVEMENT AND PROPERTIES


if (allowghost == 1){

if (cooldown3 == 0){

    if (is_collision(ghost1.x().integer(),ghost1.y().integer(), main_hero.x().integer(),main_hero.y().integer())){
        
        bn::string<64> message5 = "Avoid the Ghost!";
        show_temporary_text(text_generator, bn::fixed_point(-40, 65), message5, 60);

        ghost1.set_x(ghost1.x() = -46);
        ghost1.set_y(ghost1.y() = -54);
        allowghost = 0;
        main_hero.set_x(34);
        main_hero.set_y(-70);

        playerX2 = 19;
        playerY2 = 1;
        health = health - 1;

    }
    

    if (direction == 0){

    if (ghost1.x() == main_hero.x()){
        direction = 1;
    }
        

    if ((ghost1.x() < main_hero.x())){
        
        ghost1.set_x(ghost1.x() + 0.5);
        }
        
    
    else{
        
        ghost1.set_x(ghost1.x() - 0.5);
        }
    }
        
    

else{

    if (ghost1.y() == main_hero.y()){
        direction = 0;
    }

    if ((ghost1.y() < main_hero.y())){
        
        ghost1.set_y(ghost1.y() + 0.5);
        }
        
    
    else{
        
        ghost1.set_y(ghost1.y() - 0.5);
        }
        
    }
}

else{
    cooldown3 = cooldown3 - 1;
}
}
    


////////////////////////////////
//////// ZOMBIE collision with player


if (allowZ == 1){
if ((zombie4.x().integer() == main_hero.x().integer()) && (zombie4.y().integer() == main_hero.y().integer())){
                bn::string<64> message5 = "Avoid the zombies!";
                show_temporary_text(text_generator, bn::fixed_point(-40, 65), message5, 60);
                main_hero.set_x(main_hero.x() = 34);
                main_hero.set_y(main_hero.y() = -70);
                playerX2 = 19;
                playerY2 = 1; 
                health = health - 1;
                allowghost = 0;
                ghost1.set_x(ghost1.x() = -46);
                ghost1.set_y(ghost1.y() = -54);
}


if ((zombie5.x().integer() == main_hero.x().integer()) && (zombie5.y().integer() == main_hero.y().integer())){
    bn::string<64> message5 = "Avoid the zombies!";
    show_temporary_text(text_generator, bn::fixed_point(-40, 65), message5, 60);
    main_hero.set_x(main_hero.x() = 34);
    main_hero.set_y(main_hero.y() = -70);
    playerX2 = 19;
    playerY2 = 1; 
    health = health - 1;
    allowghost = 0;
    ghost1.set_x(ghost1.x() = -46);
    ghost1.set_y(ghost1.y() = -54);
}

}



/////////////////////////////////////////////////////////////////////////// 
////zombie 4 movement


if ((random4 == 0) && (allowZ == 1)){
    if (collisionMap2[zombieY4 + 1][zombieX4] == 0){
        if (cooldown == 0){    
        zombieY4++;
        zombie4.set_y(zombie4.y() + 8);
        cooldown = 20;
        }
        
        else{
        cooldown = cooldown - 1;
        }
    }
    else {
        random_index = rng.get_int(2);
        random4 = options0[random_index];
    }
  
}



if ((random4 == 1) && (allowZ == 1)){
    if ((collisionMap2[zombieY4 - 1][zombieX4] == 0)){
        if (cooldown == 0){
        zombieY4--;
        zombie4.set_y(zombie4.y() - 8);
        cooldown = 20;
        }
        else{
        cooldown = cooldown - 1;
        }
    }
    else{
        random_index = rng.get_int(2);
        random4 = options0[random_index];
    }
}
    

if ((random4 == 2) && (allowZ == 1)){
    if ((collisionMap2[zombieY4][zombieX4+1] == 0)){
        if (cooldown == 0){
        zombieX4++;
        zombie4.set_x(zombie4.x() + 8);
        cooldown = 20;
        }
        else{
        cooldown = cooldown - 1;
        }
    }
    else{
        random_index = rng.get_int(2);
        random4 = options1[random_index];
    }
}
    


if ((random4 == 3) && (allowZ == 1)){
    if ((collisionMap2[zombieY4][zombieX4 - 1] == 0)){ 
            if (cooldown == 0){        
            zombieX4--;
            zombie4.set_x(zombie4.x() - 8);
            cooldown = 20;
            }
            else{
                cooldown = cooldown - 1;
            }
        }
        else{
            random_index = rng.get_int(2);
            random4 = options1[random_index];
        }
    }


    /////////////////////////////////////////////////////////////////////////// 
////zombie 5 movement


if ((random5 == 0) && (allowZ == 1)){
    if (collisionMap2[zombieY5 + 1][zombieX5] == 0){
        if (cooldown == 0){    
        zombieY5++;
        zombie5.set_y(zombie5.y() + 8);
        cooldown = 20;
        }
        
        else{
        cooldown = cooldown - 1;
        }
    }
    else {
        random_index = rng.get_int(2);
        random5 = options0[random_index];
    }
  
}



if ((random5 == 1) && (allowZ == 1)){
    if ((collisionMap2[zombieY5 - 1][zombieX5] == 0)){
        if (cooldown == 0){
        zombieY5--;
        zombie5.set_y(zombie5.y() - 8);
        cooldown = 20;
        }
        else{
        cooldown = cooldown - 1;
        }
    }
    else{
        random_index = rng.get_int(2);
        random5 = options0[random_index];
    }
}
    

if ((random5 == 2) && (allowZ == 1)){
    if ((collisionMap2[zombieY5][zombieX5+1] == 0)){
        if (cooldown == 0){
        zombieX5++;
        zombie5.set_x(zombie5.x() + 8);
        cooldown = 20;
        }
        else{
        cooldown = cooldown - 1;
        }
    }
    else{
        random_index = rng.get_int(2);
        random5 = options1[random_index];
    }
}
    


if ((random5 == 3) && (allowZ == 1)){
    if ((collisionMap2[zombieY5][zombieX5 - 1] == 0)){ 
            if (cooldown == 0){        
            zombieX5--;
            zombie5.set_x(zombie5.x() - 8);
            cooldown = 20;
            }
            else{
                cooldown = cooldown - 1;
            }
        }
        else{
            random_index = rng.get_int(2);
            random5 = options1[random_index];
        }
    }









        // Update screen
        bn::core::update();
    }


}
