#include "main.h"

int main() 
{
    Application game;
    game.run();


    /*sf::RenderWindow window(sf::VideoMode(1440, 920), "Crossy Road", sf::Style::Close);
    sf::Texture texture;
    texture.loadFromFile("Material/Animations/road.jpg");
    obstacle* tmp = new obstacle(150, sf::Vector2f(0, 0.1), &texture);
    tmp->setPosition(sf::Vector2f(0, 400));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }
        window.clear();
        tmp -> drawTo(window);
        window.display();
    }*/

    //sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Crossy Road", sf::Style::Close);

    /*sf::Texture chickenTex;
    if (!chickenTex.loadFromFile("Material/Animations/Chicken.png"))
        std::cout << "Chicken not found!\n";

    Character chicken(&chickenTex, sf::Vector2u(4, 5), 0.1f, 100.0f);*/


    /*sf::Font font;
    if (!font.loadFromFile("font/HIEN KHANH 3.ttf"))
        std::cout << "HIEN KHANH 3 not found!\n";*/

    /*std::vector<Button*> accounts;

    for (int i = 0; i < 10; ++i)
    {
        Button* tmp = new Button("Hello World!", { 600.f, 75.f }, 25, sf::Color::Green, sf::Color::Black);
        tmp->setPosition({ 450.f, 200.f + i * 90.f});
        tmp->setOutlineThickness(2.f);
        tmp->setFont(font);
        accounts.push_back(tmp);
    }*/

    /*sf::Texture accountTex;
    if (!accountTex.loadFromFile("Material/Buttons/Account.png"))
        std::cout << "Account not found!\n";

    AccountButton account("Hello World!", { 860.f, 130.f }, 35, sf::Color::Transparent, sf::Color::Black, &accountTex, std::to_string(10000));
    account.setFont(font);
    account.setPosition({ 200.f, 200.f });
    account.setBackgroundAnimation(&accountTex);*/

    //float deltaTime = 0.0f;
    //sf::Clock clock;

    //while (window.isOpen())
    //{
    ////    deltaTime = clock.restart().asSeconds();

    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        switch (event.type)
    //        {
    //        case sf::Event::Closed:
    //            window.close();
    //            break;
    //        }
    //    }

    ////    for (int i = 0; i < 10; ++i)
    ////    {
    ////        accounts[i]->update(window);
    ////    }
    ////    deleteButton.update(window);
    ////    window.clear();
    ////    for (int i = 0; i < 10; ++i)
    ////    {
    ////        accounts[i]->drawTo(window);
    ////    }

    ////    chicken.update(deltaTime);

    //    account.update(window);

    //    window.clear(sf::Color::White);

    //    account.drawTo(window);
    ////    chicken.drawTo(window);

    //    window.display();
    //}

    return 0;
}