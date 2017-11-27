#include <SFML/Graphics.hpp>
#include <array>
#include "HowToPlay.h"
#include "Global.h"

int HowtoplayScreen() {
    sf::Text Title;
    Title.setFont(Font[PRINCEVALIANT]);
    Title.setString("How To Play");
    Title.setCharacterSize(80);
    Title.setColor(sf::Color(27,128,255,255));
    Title.setOrigin(Title.getGlobalBounds().width/2,0);
    Title.setPosition(400,20);

    std::vector<sf::Text> Index;
    std::vector<std::string> IndexStrings={"Introduction","Controls","Power","Skill","Spirit","Items","Enemies","Boss Battles","Back to main menu"};
    for (unsigned i=0; i<IndexStrings.size(); ++i) {
        Index.push_back(sf::Text());
        Index.back().setFont(Font[PRINCEVALIANT]);
        Index.back().setString(IndexStrings[i]);
        Index.back().setCharacterSize(40);
        Index.back().setColor(sf::Color(128,128,128,255));
        Index.back().setPosition(15,150+45*i);
    }

    //Story introduction

    std::string introduction_text_string(   "Welcome to The Sins Awakening!\n\n"
                                            ""
                                            "In a land devastated by the return of \n"
                                            "the Seven Deadly Sins, there are \n"
                                            "still humans who hope for a better \n"
                                            "future, and are ready to fight.\n\n"
                                            ""
                                            "Now it's your turn to challenge the Sins.\n"
                                            "Pick either Ater, a well-trained soldier, \n"
                                            "or Alba, a young student, and defeat \n"
                                            "the Sins once again.");
    sf::Text introduction_text;
    introduction_text.setFont(Font[TUFFY]);
    introduction_text.setString(introduction_text_string);
    introduction_text.setCharacterSize(25);
    introduction_text.setColor(sf::Color(255,255,255));
    introduction_text.setPosition(325,160);

    //Controls-1

    std::string controls_menu_title_string("Menu controls");
    std::string controls_menu_keys_string(  "Arrow keys\n"
                                            "Z\n"
                                            "X\n\n"
                                            ""
                                            "F1 (Main menu)\n"
                                            "P");
    std::string controls_menu_what_string("- Navigate menu\n"
                                          "- Confirm\n"
                                          "- Return\n\n"
                                          ""
                                          "- Toggle Fullscreen mode\n"
                                          "- Screenshot");
    sf::Text controls_menu_title_text;
    controls_menu_title_text.setFont(Font[PRINCEVALIANT]);
    controls_menu_title_text.setString(controls_menu_title_string);
    controls_menu_title_text.setCharacterSize(45);
    controls_menu_title_text.setColor(sf::Color(27,128,255));
    controls_menu_title_text.setPosition(400,150);

    sf::Text controls_menu_keys_text;
    controls_menu_keys_text.setFont(Font[TUFFY]);
    controls_menu_keys_text.setString(controls_menu_keys_string);
    controls_menu_keys_text.setCharacterSize(25);
    controls_menu_keys_text.setColor(sf::Color(255,255,255));
    controls_menu_keys_text.setPosition(325,225);

    sf::Text controls_menu_what_text;
    controls_menu_what_text.setFont(Font[TUFFY]);
    controls_menu_what_text.setString(controls_menu_what_string);
    controls_menu_what_text.setCharacterSize(25);
    controls_menu_what_text.setColor(sf::Color(255,255,255));
    controls_menu_what_text.setPosition(500,225);

    //Controls-2

    std::string controls_game_title_string("Game controls");
    std::string controls_game_keys_string(  "Arrow keys\n"
                                            "Z\n"
                                            "X\n"
                                            "C\n"
                                            "Left Shift\n\n"
                                            ""
                                            "Esc\n"
                                            "P");
    std::string controls_game_what_string("- Move\n"
                                          "- Shoot / Scroll dialogues\n"
                                          "- Skill\n"
                                          "- Spirit Unleashing\n"
                                          "- Slow movement\n\n"
                                          ""
                                          "- Pause\n"
                                          "- Screenshot");
    sf::Text controls_game_title_text;
    controls_game_title_text.setFont(Font[PRINCEVALIANT]);
    controls_game_title_text.setString(controls_game_title_string);
    controls_game_title_text.setCharacterSize(45);
    controls_game_title_text.setColor(sf::Color(27,128,255));
    controls_game_title_text.setPosition(400,150);

    sf::Text controls_game_keys_text;
    controls_game_keys_text.setFont(Font[TUFFY]);
    controls_game_keys_text.setString(controls_game_keys_string);
    controls_game_keys_text.setCharacterSize(25);
    controls_game_keys_text.setColor(sf::Color(255,255,255));
    controls_game_keys_text.setPosition(325,225);

    sf::Text controls_game_what_text;
    controls_game_what_text.setFont(Font[TUFFY]);
    controls_game_what_text.setString(controls_game_what_string);
    controls_game_what_text.setCharacterSize(25);
    controls_game_what_text.setColor(sf::Color(255,255,255));
    controls_game_what_text.setPosition(500,225);

    //Power

    sf::Sprite power_sprite;
    char* imagebuffer=Reader.getFile("Howtoplay_0.png");
    size_t imagesize=Reader.getEntryFileSize("Howtoplay_0.png");
    sf::Texture power_texture;
    power_texture.loadFromMemory(imagebuffer,imagesize);
    delete[] imagebuffer;
    power_sprite.setTexture(power_texture);
    power_sprite.setOrigin(power_texture.getSize().x/2, 0);
    power_sprite.setPosition(525,140);

    std::string power_string("The Power meter is related to your firing speed.\n"
                             "It is increased by collecting Power Items, and \n"
                             "the higher it is, the faster your secondary \n"
                             "weapon will shoot.\n\n"
                             ""
                             "Under the power meter, the Energy bar shows how \n"
                             "long the secondary weapon can fire.\n"
                             "If it's empty, the secondary weapon will not fire.\n"
                             "If it's full, the secondary weapon will attract all \n"
                             "items on screen towards the player character.\n"
                             "The Energy bar refills by itself when not shooting.");
    sf::Text power_text;
    power_text.setFont(Font[TUFFY]);
    power_text.setString(power_string);
    power_text.setCharacterSize(20);
    power_text.setColor(sf::Color(255,255,255));
    power_text.setPosition(325,260);

    //Skill-1

    std::string skill_one_string("Skills are special moves you can use in\n"
                                 "dangerous situations.\n\n"
                                 ""
                                 "Each character has his or her own skill,\n"
                                 "which can be used for different purposes.\n\n"
                                 ""
                                 "To use a skill, you must have one \n"
                                 "available.\n"
                                 "Skill uses can be dropped by enemies \n"
                                 "as Skill Items.\n"
                                 "Skill uses also refill when you lose a life.");
    sf::Text skill_one_text;
    skill_one_text.setFont(Font[TUFFY]);
    skill_one_text.setString(skill_one_string);
    skill_one_text.setCharacterSize(25);
    skill_one_text.setColor(sf::Color(255,255,255));
    skill_one_text.setPosition(325,160);

    //Skill-2

    imagebuffer=Reader.getFile("Howtoplay_1.png");
    imagesize=Reader.getEntryFileSize("Howtoplay_1.png");
    sf::Texture skill_two_texture;
    skill_two_texture.loadFromMemory(imagebuffer,imagesize);
    delete[] imagebuffer;
    sf::Sprite skill_two_sprite;
    skill_two_sprite.setTexture(skill_two_texture);
    skill_two_sprite.setPosition(325,150);

    //Skill-3

    imagebuffer=Reader.getFile("Howtoplay_2.png");
    imagesize=Reader.getEntryFileSize("Howtoplay_2.png");
    sf::Texture skill_three_texture;
    skill_three_texture.loadFromMemory(imagebuffer,imagesize);
    delete[] imagebuffer;
    sf::Sprite skill_three_sprite;
    skill_three_sprite.setTexture(skill_three_texture);
    skill_three_sprite.setPosition(325,150);

    //Spirit

    imagebuffer=Reader.getFile("Howtoplay_3.png");
    imagesize=Reader.getEntryFileSize("Howtoplay_3.png");
    sf::Texture spirit_texture;
    spirit_texture.loadFromMemory(imagebuffer, imagesize);
    delete[] imagebuffer;
    sf::Sprite spirit_sprite;
    spirit_sprite.setTexture(spirit_texture);
    spirit_sprite.setOrigin(spirit_texture.getSize().x/2,0);
    spirit_sprite.setPosition(525,140);

    std::string spirit_string("The Spirit Unleashing is the true expression\n"
                              "of the power of one's soul.\n"
                              "Grazing enemy bullets will fill the Spirit meter.\n"
                              "When it reaches 10, the Spirit Unleashing can begin.\n"
                              "Each character releases his spirit differently, with\n"
                              "Ater bringing destruction at lightning speed and Alba\n"
                              "finally expressing the true, fearful power of her \n"
                              "magic.\n\n"
                              ""
                              "During the 10 seconds of the Spirit Unleashing, both\n"
                              "characters are invincible and can use their skill, be\n"
                              "it for additional damage (Ater) or for a safer return\n"
                              "to normal conditions (Alba).");
    sf::Text spirit_text;
    spirit_text.setFont(Font[TUFFY]);
    spirit_text.setString(spirit_string);
    spirit_text.setCharacterSize(20);
    spirit_text.setColor(sf::Color(255,255,255));
    spirit_text.setPosition(325,210);

    //Items-1

    std::string items_one_string("Items are key in both survival and \n"
                                 "scoring. They appear when defeating \n"
                                 "an enemy or a boss pattern, and are \n"
                                 "collected by getting near them.\n\n"
                                 ""
                                 "There are different kinds of items, with\n"
                                 "the rarer ones only dropped by the\n"
                                 "strongest enemies.");
    sf::Text items_one_text;
    items_one_text.setFont(Font[TUFFY]);
    items_one_text.setString(items_one_string);
    items_one_text.setCharacterSize(25);
    items_one_text.setColor(sf::Color(255,255,255));
    items_one_text.setPosition(325,200);

    //Items-2

    sf::Sprite items_two_sprite_one;
    items_two_sprite_one.setTexture(Engine.ItemImages[POWER_ITEM]);
    items_two_sprite_one.setPosition(400,167);

    std::string items_two_name_one_string("- Power Item");
    sf::Text items_two_name_one_text;
    items_two_name_one_text.setFont(Font[TUFFY]);
    items_two_name_one_text.setString(items_two_name_one_string);
    items_two_name_one_text.setCharacterSize(25);
    items_two_name_one_text.setColor(sf::Color(255,255,255));
    items_two_name_one_text.setPosition(440,160);

    std::string items_two_desc_one_string("Increases Power by 0.05 and refills half\n"
                                          "of the Energy bar.\n"
                                          "Adds score if Power is already 10.00.");
    sf::Text items_two_desc_one_text;
    items_two_desc_one_text.setFont(Font[TUFFY]);
    items_two_desc_one_text.setString(items_two_desc_one_string);
    items_two_desc_one_text.setCharacterSize(25);
    items_two_desc_one_text.setColor(sf::Color(255,255,255));
    items_two_desc_one_text.setPosition(325,215);

    sf::Sprite items_two_sprite_two;
    items_two_sprite_two.setTexture(Engine.ItemImages[SCORE_ITEM]);
    items_two_sprite_two.setPosition(400,317+35);

    std::string items_two_name_two_string("- Score Item");
    sf::Text items_two_name_two_text;
    items_two_name_two_text.setFont(Font[TUFFY]);
    items_two_name_two_text.setString(items_two_name_two_string);
    items_two_name_two_text.setCharacterSize(25);
    items_two_name_two_text.setColor(sf::Color(255,255,255));
    items_two_name_two_text.setPosition(440,310+35);

    std::string items_two_desc_two_string("Increases Score.\n"
                                          "Gained score varies depending \n"
                                          "on how full the Energy bar is.");
    sf::Text items_two_desc_two_text;
    items_two_desc_two_text.setFont(Font[TUFFY]);
    items_two_desc_two_text.setString(items_two_desc_two_string);
    items_two_desc_two_text.setCharacterSize(25);
    items_two_desc_two_text.setColor(sf::Color(255,255,255));
    items_two_desc_two_text.setPosition(325,365+35);

    //Items-2

    sf::Sprite items_three_sprite_one;
    items_three_sprite_one.setTexture(Engine.ItemImages[BOMB_ITEM]);
    items_three_sprite_one.setPosition(400,167);

    std::string items_three_name_one_string("- Skill Item");
    sf::Text items_three_name_one_text;
    items_three_name_one_text.setFont(Font[TUFFY]);
    items_three_name_one_text.setString(items_three_name_one_string);
    items_three_name_one_text.setCharacterSize(25);
    items_three_name_one_text.setColor(sf::Color(255,255,255));
    items_three_name_one_text.setPosition(440,160);

    std::string items_three_desc_one_string("Adds a Skill use to the available stock.\n"
                                            "If the Skill stock is full, score is gained.");
    sf::Text items_three_desc_one_text;
    items_three_desc_one_text.setFont(Font[TUFFY]);
    items_three_desc_one_text.setString(items_three_desc_one_string);
    items_three_desc_one_text.setCharacterSize(25);
    items_three_desc_one_text.setColor(sf::Color(255,255,255));
    items_three_desc_one_text.setPosition(325,215);

    sf::Sprite items_three_sprite_two;
    items_three_sprite_two.setTexture(Engine.ItemImages[LIFE_ITEM]);
    items_three_sprite_two.setPosition(400,317+35);

    std::string items_three_name_two_string("- Life Item");
    sf::Text items_three_name_two_text;
    items_three_name_two_text.setFont(Font[TUFFY]);
    items_three_name_two_text.setString(items_three_name_two_string);
    items_three_name_two_text.setCharacterSize(25);
    items_three_name_two_text.setColor(sf::Color(255,255,255));
    items_three_name_two_text.setPosition(440,310+35);

    std::string items_three_desc_two_string("Adds a Life to the available stock.\n"
                                            "If the Life stock is full, this item acts\n"
                                            "as a Skill Item.");
    sf::Text items_three_desc_two_text;
    items_three_desc_two_text.setFont(Font[TUFFY]);
    items_three_desc_two_text.setString(items_three_desc_two_string);
    items_three_desc_two_text.setCharacterSize(25);
    items_three_desc_two_text.setColor(sf::Color(255,255,255));
    items_three_desc_two_text.setPosition(325,365+35);

    //Enemies-1

    sf::Sprite enemies_one_sprite;
    enemies_one_sprite.setTexture(Engine.EnemyImages[0]);
    enemies_one_sprite.setTextureRect(sf::IntRect(0,0,Engine.EnemyImages[0].getSize().x/4,Engine.EnemyImages[0].getSize().y));
    enemies_one_sprite.setOrigin(enemies_one_sprite.getLocalBounds().width/2,enemies_one_sprite.getLocalBounds().height/2);
    enemies_one_sprite.setColor(sf::Color(192,64,64));
    enemies_one_sprite.setPosition(500,200);

     std::string enemies_one_name_string("Will-o'-Wisp\n\n");
    sf::Text enemies_one_name_text;
    enemies_one_name_text.setFont(Font[TUFFY]);
    enemies_one_name_text.setString(enemies_one_name_string);
    enemies_one_name_text.setCharacterSize(30);
    enemies_one_name_text.setColor(sf::Color(255,255,255));
    enemies_one_name_text.setOrigin(enemies_one_name_text.getLocalBounds().width/2, enemies_one_name_text.getLocalBounds().height/2);
    enemies_one_name_text.setPosition(ceil(500),ceil(310));

    std::string enemies_one_desc_string("The weakest enemy.\n"
                                        "Because of its weakness, it\n"
                                        "is often found in groups.");
    sf::Text enemies_one_desc_text;
    enemies_one_desc_text.setFont(Font[TUFFY]);
    enemies_one_desc_text.setString(enemies_one_desc_string);
    enemies_one_desc_text.setCharacterSize(30);
    enemies_one_desc_text.setColor(sf::Color(255,255,255));
    enemies_one_desc_text.setPosition(325,325);

    //Enemies-2

    sf::Sprite enemies_two_sprite;
    enemies_two_sprite.setTexture(Engine.EnemyImages[1]);
    enemies_two_sprite.setTextureRect(sf::IntRect(0,0,Engine.EnemyImages[1].getSize().x/4,Engine.EnemyImages[1].getSize().y));
    enemies_two_sprite.setOrigin(enemies_two_sprite.getLocalBounds().width/2,enemies_two_sprite.getLocalBounds().height/2);
    enemies_two_sprite.setPosition(500,200);

     std::string enemies_two_name_string("Wicked Wizard\n\n");
    sf::Text enemies_two_name_text;
    enemies_two_name_text.setFont(Font[TUFFY]);
    enemies_two_name_text.setString(enemies_two_name_string);
    enemies_two_name_text.setCharacterSize(30);
    enemies_two_name_text.setColor(sf::Color(255,255,255));
    enemies_two_name_text.setOrigin(enemies_two_name_text.getLocalBounds().width/2, enemies_two_name_text.getLocalBounds().height/2);
    enemies_two_name_text.setPosition(ceil(500),ceil(310));

    std::string enemies_two_desc_string("A stronger enemy, able to take\n"
                                        "more hits. He can shoot more  \n"
                                        "complex patterns, but the \n"
                                        "rewarded loot is better too.");
    sf::Text enemies_two_desc_text;
    enemies_two_desc_text.setFont(Font[TUFFY]);
    enemies_two_desc_text.setString(enemies_two_desc_string);
    enemies_two_desc_text.setCharacterSize(30);
    enemies_two_desc_text.setColor(sf::Color(255,255,255));
    enemies_two_desc_text.setPosition(325,325);

    //Enemies-3

    sf::Sprite enemies_three_sprite;
    enemies_three_sprite.setTexture(Engine.EnemyImages[2]);
    enemies_three_sprite.setTextureRect(sf::IntRect(0,0,Engine.EnemyImages[2].getSize().x/4,Engine.EnemyImages[2].getSize().y));
    enemies_three_sprite.setOrigin(enemies_three_sprite.getLocalBounds().width/2,enemies_three_sprite.getLocalBounds().height/2);
    enemies_three_sprite.setPosition(500,200);

    sf::Sprite enemies_three_aura_sprite;
    enemies_three_aura_sprite.setTexture(Engine.BossAuraImage);
    enemies_three_aura_sprite.setColor(sf::Color(64,64,64));
    enemies_three_aura_sprite.setOrigin(Engine.BossAuraImage.getSize().x/2,Engine.BossAuraImage.getSize().y/2);
    enemies_three_aura_sprite.setPosition(500,200);

     std::string enemies_three_name_string("Dark Lieutenant\n\n");
    sf::Text enemies_three_name_text;
    enemies_three_name_text.setFont(Font[TUFFY]);
    enemies_three_name_text.setString(enemies_three_name_string);
    enemies_three_name_text.setCharacterSize(30);
    enemies_three_name_text.setColor(sf::Color(255,255,255));
    enemies_three_name_text.setOrigin(enemies_three_name_text.getLocalBounds().width/2, enemies_three_name_text.getLocalBounds().height/2);
    enemies_three_name_text.setPosition(ceil(500),ceil(310));

    std::string enemies_three_desc_string(  "The strongest enemy, his fearsome\n"
                                            "power is nearly that of the Sins\n"
                                            "themselves.\n"
                                            "As he always carries very good\n"
                                            "items with him, defeating him is\n"
                                            "surely worth it.");
    sf::Text enemies_three_desc_text;
    enemies_three_desc_text.setFont(Font[TUFFY]);
    enemies_three_desc_text.setString(enemies_three_desc_string);
    enemies_three_desc_text.setCharacterSize(25);
    enemies_three_desc_text.setColor(sf::Color(255,255,255));
    enemies_three_desc_text.setPosition(325,325);

    //Boss Battles-1

    std::string boss_one_string("At the end of each level, you will\n"
                                "have to face one of the Sins.\n\n"
                                ""
                                "The Sins will attack you with a set\n"
                                "of patterns, switching to the next one\n"
                                "as the current one's health bar\n"
                                "completely depletes.\n\n"
                                ""
                                "Watch out for their fierce attacks,\n"
                                "and defeat them by bringing the last\n"
                                "pattern's health down to 0.");
    sf::Text boss_one_text;
    boss_one_text.setFont(Font[TUFFY]);
    boss_one_text.setString(boss_one_string);
    boss_one_text.setCharacterSize(25);
    boss_one_text.setColor(sf::Color(255,255,255));
    boss_one_text.setPosition(325,165);

    //Boss Battles-2

    sf::Texture boss_two_texture;
    imagebuffer=Reader.getFile("Howtoplay_5.png");
    imagesize=Reader.getEntryFileSize("Howtoplay_5.png");
    boss_two_texture.loadFromMemory(imagebuffer, imagesize);
    delete[] imagebuffer;
    boss_two_texture.setSmooth(true);

    sf::Sprite boss_two_sprite;
    boss_two_sprite.setTexture(boss_two_texture);
    boss_two_sprite.setPosition(340,160);
    boss_two_sprite.setScale(0.75f, 0.75f);

    //Boss Battles-3

    sf::Texture boss_three_texture;
    imagebuffer=Reader.getFile("Howtoplay_6.png");
    imagesize=Reader.getEntryFileSize("Howtoplay_6.png");
    boss_three_texture.loadFromMemory(imagebuffer, imagesize);
    delete[] imagebuffer;
    boss_three_texture.setSmooth(true);

    sf::Sprite boss_three_sprite;
    boss_three_sprite.setTexture(boss_three_texture);
    boss_three_sprite.setPosition(340,160);
    boss_three_sprite.setScale(0.75f, 0.75f);

    std::string boss_three_string("The pink bar at the top of the screen\n"
                                  "shows the current pattern's health.\n\n"
                                  ""
                                  "Shooting the boss will cause the bar\n"
                                  "to deplete. Once it is empty, the boss\n"
                                  "will switch to the next pattern, if\n"
                                  "available.\n\n"
                                  ""
                                  "The Health bar also depletes as time\n"
                                  "passes.");
    sf::Text boss_three_text;
    boss_three_text.setFont(Font[TUFFY]);
    boss_three_text.setString(boss_three_string);
    boss_three_text.setCharacterSize(20);
    boss_three_text.setColor(sf::Color(255,255,255));
    boss_three_text.setPosition(350,250);

    //Boss Battles-4

    std::string boss_four_string("The number under the Health bar, on the\n"
                                 "left, tells how many patterns the boss\n"
                                 "will use after the current one.\n\n"
                                 ""
                                 "When that number reaches 0, clearing the\n"
                                 "current pattern will cause the boss to be\n"
                                 "defeated.");
    sf::Text boss_four_text;
    boss_four_text.setFont(Font[TUFFY]);
    boss_four_text.setString(boss_four_string);
    boss_four_text.setCharacterSize(20);
    boss_four_text.setColor(sf::Color(255,255,255));
    boss_four_text.setPosition(350,250);

    //Boss Battles-5

    std::string boss_five_string("The Score Bonus is a reward for clearing\n"
                                 "a pattern.\n\n"
                                 ""
                                 "In order to get it, the player must not\n"
                                 "get hit, use his or her Skill, nor be in\n"
                                 "Spirit Unleashing mode.\n"
                                 "Doing any of these will cause the Score\n"
                                 "Bonus to drop to 0.\n\n"
                                 ""
                                 "Try your best to clear patterns and get\n"
                                 "the Score Bonus!");
    sf::Text boss_five_text;
    boss_five_text.setFont(Font[TUFFY]);
    boss_five_text.setString(boss_five_string);
    boss_five_text.setCharacterSize(20);
    boss_five_text.setColor(sf::Color(255,255,255));
    boss_five_text.setPosition(350,250);

    //Boss Battles-6

    std::string boss_six_string("When facing a pattern, the Graze counter\n"
                                 "will stop increasing.\n"
                                 ""
                                 "The total amount of Grazes will be\n"
                                 "awarded all at once, when the pattern\n"
                                 "is cleared. Before doing so, however, it\n"
                                 "will be multiplied by the Graze Multiplier,\n"
                                 "which increases as you shoot the boss.\n\n"
                                 ""
                                 "The Spirit meter will not be affected by the\n"
                                 "Graze Multiplier and will fill as usual.");
    sf::Text boss_six_text;
    boss_six_text.setFont(Font[TUFFY]);
    boss_six_text.setString(boss_six_string);
    boss_six_text.setCharacterSize(20);
    boss_six_text.setColor(sf::Color(255,255,255));
    boss_six_text.setPosition(350,250);

    //Pages

    std::string pages_str("0 / 0");
    sf::Text pages_text;
    pages_text.setFont(Font[TUFFY]);
    pages_text.setString(pages_str);
    pages_text.setCharacterSize(25);
    pages_text.setColor(sf::Color(255,255,255));
    pages_text.setOrigin(pages_text.getGlobalBounds().width/2,0);
    pages_text.setPosition(550,557);

    sf::Sprite Arrows[2];
    for (int i=0; i<2; ++i) {
        Arrows[i].setTexture(Engine.ArrowImage);
        Arrows[i].setScale(0.3*(i==0?-1:1),0.25);
        Arrows[i].setColor(sf::Color(128,128,128));
    }
    Arrows[0].setPosition(500,560);
    Arrows[1].setPosition(600,560);

    size_t currentpage=1;
    std::vector<size_t> pages={1,2,1,3,1,3,3,6,1};

    //Loop
    unsigned short Selected=1;
    bool InHowtoplayMenu=true;
    MainBackgroundSprite.setColor(sf::Color(0,0,128,255));
    while (InHowtoplayMenu) {
        while (MainWindow.pollEvent(Event)) {
            if (Event.type==sf::Event::KeyPressed) {
                switch (Event.key.code) {
                    case sf::Keyboard::Up:
                        if (Selected > 1) Selected--;
                        else Selected=Index.size();
                        currentpage=1;
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::Down:
                        if (Selected < Index.size()) Selected++;
                        else Selected=1;
                        currentpage=1;
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::Left:
                        currentpage=std::max<int>(currentpage-1,1);
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::Right:
                        currentpage=std::min<int>(currentpage+1,pages[Selected-1]);
                        Play(MENUSCROLL);
                        break;
                    case sf::Keyboard::X:
                    case sf::Keyboard::Escape:
                        if (Selected!=Index.size()) {
                            Selected=Index.size();
                            Play(MENUSCROLL);
                            break;
                        }
                        //No break -> else case Z
                    case sf::Keyboard::Z:
                        if (Selected==Index.size()) {
                            InHowtoplayMenu=false;
                            Play(MENUCONFIRM);
                        }
                        break;
                    case sf::Keyboard::P:
                        Engine.ScreenShot();
                        break;
                    case sf::Keyboard::LAlt:
                        Engine.LAltPressed=true;
                        break;
                    case sf::Keyboard::F4:
                        Engine.F4Pressed=true;
                        break;
                    default: break;
                }
            }
            else if (Event.type==sf::Event::KeyReleased) {
                switch (Event.key.code) {
                    case sf::Keyboard::LAlt:
                        Engine.LAltPressed=false;
                        break;
                    case sf::Keyboard::F4:
                        Engine.F4Pressed=false;
                        break;
                    default:
                        break;
                }
            }
            else if (Event.type==sf::Event::Closed)
                Engine.CrossPressed=true;
        }
        CHECK_EXIT();
        MainWindow.clear();

        for (unsigned i=0; i<Index.size(); ++i) {
            if (i==static_cast<unsigned>(Selected-1))
                Index[i].setColor(sf::Color(255,255,255));
            else
                Index[i].setColor(sf::Color(128,128,128));
        }

        MainWindow.draw(MainBackgroundSprite);
        MainWindow.draw(Title);
        for (auto index : Index)
            MainWindow.draw(index);
        switch (Selected) {
        case 1:
            MainWindow.draw(introduction_text);
            break;
        case 2:
            if (currentpage==1) {
                MainWindow.draw(controls_menu_title_text);
                MainWindow.draw(controls_menu_keys_text);
                MainWindow.draw(controls_menu_what_text);
            }
            else {
                MainWindow.draw(controls_game_title_text);
                MainWindow.draw(controls_game_keys_text);
                MainWindow.draw(controls_game_what_text);
            }
            break;
        case 3:
            MainWindow.draw(power_sprite);
            MainWindow.draw(power_text);
            break;
        case 4:
            if (currentpage==1) {
                MainWindow.draw(skill_one_text);
            }
            else if (currentpage==2) {
                MainWindow.draw(skill_two_sprite);
            }
            else if (currentpage==3) {
                MainWindow.draw(skill_three_sprite);
            }
            break;
        case 5:
            MainWindow.draw(spirit_sprite);
            MainWindow.draw(spirit_text);
            break;
        case 6:
            if (currentpage==1) {
                MainWindow.draw(items_one_text);
            }
            else if (currentpage==2) {
                MainWindow.draw(items_two_sprite_one);
                MainWindow.draw(items_two_name_one_text);
                MainWindow.draw(items_two_desc_one_text);
                MainWindow.draw(items_two_sprite_two);
                MainWindow.draw(items_two_name_two_text);
                MainWindow.draw(items_two_desc_two_text);
            }
            else if (currentpage==3) {
                MainWindow.draw(items_three_sprite_one);
                MainWindow.draw(items_three_name_one_text);
                MainWindow.draw(items_three_desc_one_text);
                MainWindow.draw(items_three_sprite_two);
                MainWindow.draw(items_three_name_two_text);
                MainWindow.draw(items_three_desc_two_text);
            }
            break;
        case 7:
            if (currentpage==1) {
                MainWindow.draw(enemies_one_sprite);
                MainWindow.draw(enemies_one_name_text);
                MainWindow.draw(enemies_one_desc_text);
            }
            else if (currentpage==2) {
                MainWindow.draw(enemies_two_sprite);
                MainWindow.draw(enemies_two_name_text);
                MainWindow.draw(enemies_two_desc_text);
            }
            else if (currentpage==3) {
                MainWindow.draw(enemies_three_aura_sprite);
                MainWindow.draw(enemies_three_sprite);
                MainWindow.draw(enemies_three_name_text);
                MainWindow.draw(enemies_three_desc_text);
            }
            break;
        case 8:
            if (currentpage==1) {
                MainWindow.draw(boss_one_text);
            }
            else if (currentpage==2) {
                MainWindow.draw(boss_two_sprite);
            }
            else if (currentpage==3) {
                MainWindow.draw(boss_three_sprite);
                MainWindow.draw(boss_three_text);
            }
            else if (currentpage==4) {
                MainWindow.draw(boss_three_sprite);
                MainWindow.draw(boss_four_text);
            }
            else if (currentpage==5) {
                MainWindow.draw(boss_three_sprite);
                MainWindow.draw(boss_five_text);
            }
            else if (currentpage==6) {
                MainWindow.draw(boss_three_sprite);
                MainWindow.draw(boss_six_text);
            }
        default:
            break;
        }

        if (pages[Selected-1]!=1) {
            if (currentpage==1)
                Arrows[0].setColor(sf::Color(128,128,128));
            else
                Arrows[0].setColor(sf::Color(255,255,255));

            if (currentpage==pages[Selected-1])
                Arrows[1].setColor(sf::Color(128,128,128));
            else
                Arrows[1].setColor(sf::Color(255,255,255));

            pages_str[0]='0'+currentpage;
            pages_str[4]='0'+pages[Selected-1];
            pages_text.setString(pages_str);

            MainWindow.draw(Arrows[0]);
            MainWindow.draw(Arrows[1]);
            MainWindow.draw(pages_text);
        }

        MainWindow.display();
    }
    return 0;
}
