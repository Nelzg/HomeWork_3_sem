#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#define Amp 5000.0f
#define sampleRate 44100.0f
#define n 12

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "My window");
    vector <Sound> sound(n);
    vector <SoundBuffer> buffer(n);
    vector<Int16> samples(sampleRate);
    vector<float> freq = {261.0f,277.0f,293.0f,311.0f,329.0f,349.0f,369.0f,392.0f,415.0f,440.0f,466.0f,493.0f};
    for (int j = 0; j < n; j++) {   
        for (int i = 0; i < sampleRate; i++) {
            samples[i] = Amp * sin((M_PI * 2.0f * freq[j] * float(i)) / sampleRate) + Amp;
        }
        buffer[j].loadFromSamples(&samples[0], samples.size(), 2, sampleRate);
        sound[j].setBuffer(buffer[j]);
    }
 
    while (window.isOpen())
    {
        window.clear(Color::Red);
        window.display();

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::Q)) {
            sound[0].play();
        }
        else {
            sound[0].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::W)) {
            sound[1].play();
        }
        else {
            sound[1].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::E)) {
            sound[2].play();
        }
        else {
            sound[2].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::R)) {
            sound[3].play();
        }
        else {
            sound[3].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::T)) {
            sound[4].play();
        }
        else {
            sound[4].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::Y)) {
            sound[5].play();
        }
        else {
            sound[5].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::U)) {
            sound[6].play();
        }
        else {
            sound[6].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::I)) {
            sound[7].play();
        }
        else {
            sound[7].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::O)) {
            sound[8].play();
        }
        else {
            sound[8].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::P)) {
            sound[9].play();
        }
        else {
            sound[9].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::RBracket)) {
            sound[10].play();
        }
        else {
            sound[10].stop();
        }

        if (sf::Keyboard::isKeyPressed(Keyboard::Key::LBracket)) {
            sound[11].play();
        }
        else {
            sound[11].stop();
        }
    }
    return 0;
}
