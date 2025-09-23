#include <iostream>
#include <linux/input.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <unordered_map>
#include <fstream>
#include <chrono>
std::unordered_map<int, char> mapa = {
    {KEY_A, 'a'}, {KEY_B, 'b'}, {KEY_C, 'c'}, {KEY_D, 'd'},
    {KEY_E, 'e'}, {KEY_F, 'f'}, {KEY_G, 'g'}, {KEY_H, 'h'},
    {KEY_I, 'i'}, {KEY_J, 'j'}, {KEY_K, 'k'}, {KEY_L, 'l'},
    {KEY_M, 'm'}, {KEY_N, 'n'}, {KEY_O, 'o'}, {KEY_P, 'p'},
    {KEY_Q, 'q'}, {KEY_R, 'r'}, {KEY_S, 's'}, {KEY_T, 't'},
    {KEY_U, 'u'}, {KEY_V, 'v'}, {KEY_W, 'w'}, {KEY_X, 'x'},
    {KEY_Y, 'y'}, {KEY_Z, 'z'},

    {KEY_1, '1'}, {KEY_2, '2'}, {KEY_3, '3'}, {KEY_4, '4'},
    {KEY_5, '5'}, {KEY_6, '6'}, {KEY_7, '7'}, {KEY_8, '8'},
    {KEY_9, '9'}, {KEY_0, '0'},

    {KEY_SPACE, ' '},
    {KEY_ENTER, '\n'},
};
int c_a = 0;
int c_b = 0;
int c_c = 0;
int c_d = 0;
int c_e = 0;
int c_f = 0;
int c_g = 0;
int c_h = 0;
int c_i = 0;
int c_j = 0;
int c_k = 0;
int c_l = 0;
int c_m = 0;
int c_n = 0;
int c_o = 0;
int c_p = 0;
int c_q = 0;
int c_r = 0;
int c_s = 0;
int c_t = 0;
int c_u = 0;
int c_v = 0;
int c_w = 0;
int c_x = 0;
int c_y = 0;
int c_z = 0;
int c_1 = 0;
int c_2 = 0;
int c_3 = 0;
int c_4 = 0;
int c_5 = 0;
int c_6 = 0;
int c_7 = 0;
int c_8 = 0;
int c_9 = 0;
int c_0 = 0;
int c_space = 0;
int c_enter = 0;
void LoadVars() {
    std::ifstream file("zapis");
    if (file.is_open()) {
        file >> c_a;
        file.ignore();
        file >> c_b;
        file.ignore();
        file >> c_c;
        file.ignore();
        file >> c_d;
        file.ignore();
        file >> c_e;
        file.ignore();
        file >> c_f;
        file.ignore();
        file >> c_g;
        file.ignore();
        file >> c_h;
        file.ignore();
        file >> c_i;
        file.ignore();
        file >> c_j;
        file.ignore();
        file >> c_k;
        file.ignore();
        file >> c_l;
        file.ignore();
        file >> c_m;
        file.ignore();
        file >> c_n;
        file.ignore();
        file >> c_o;
        file.ignore();
        file >> c_p;
        file.ignore();
        file >> c_q;
        file.ignore();
        file >> c_r;
        file.ignore();
        file >> c_s;
        file.ignore();
        file >> c_t;
        file.ignore();
        file >> c_u;
        file.ignore();
        file >> c_v;
        file.ignore();
        file >> c_w;
        file.ignore();
        file >> c_x;
        file.ignore();
        file >> c_y;
        file.ignore();
        file >> c_z;
        file.ignore();
        file >> c_1;
        file.ignore();
        file >> c_2;
        file.ignore();
        file >> c_3;
        file.ignore();
        file >> c_4;
        file.ignore();
        file >> c_5;
        file.ignore();
        file >> c_6;
        file.ignore();
        file >> c_7;
        file.ignore();
        file >> c_8;
        file.ignore();
        file >> c_9;
        file.ignore();
        file >> c_0;
        file.ignore();
        file >> c_space;
        file.ignore();
        file >> c_enter;
        file.ignore();
        file >> c_space;
        file.ignore();
        file.close();
    }
}
void SaveVars() {
    std::ofstream file("zapis");
    if (file.is_open()) {
        file << c_a << "\n";
        file << c_b << "\n";
        file << c_c << "\n";
        file << c_d << "\n";
        file << c_e << "\n";
        file << c_f << "\n";
        file << c_g << "\n";
        file << c_h << "\n";
        file << c_i << "\n";
        file << c_j << "\n";
        file << c_k << "\n";
        file << c_l << "\n";
        file << c_m << "\n";
        file << c_n << "\n";
        file << c_o << "\n";
        file << c_p << "\n";
        file << c_q << "\n";
        file << c_r << "\n";
        file << c_s << "\n";
        file << c_t << "\n";
        file << c_u << "\n";
        file << c_v << "\n";
        file << c_w << "\n";
        file << c_x << "\n";
        file << c_y << "\n";
        file << c_z << "\n";
        file << c_1 << "\n";
        file << c_2 << "\n";
        file << c_3 << "\n";
        file << c_4 << "\n";
        file << c_5 << "\n";
        file << c_6 << "\n";
        file << c_7 << "\n";
        file << c_8 << "\n";
        file << c_9 << "\n";
        file << c_0 << "\n";
        file << c_space << "\n";
        file << c_enter << "\n";
        file.close();
    }
}
char mapper (auto var1) {
    auto wartosc = mapa.find(var1);
    if (wartosc != mapa.end()) {
        return wartosc->second;
    } else {
        return '_';
    }
}
int main() {
    LoadVars();
    auto start = std::chrono::high_resolution_clock::now();
    const char *dev = "/dev/input/event3";
    int fd = open(dev, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    struct input_event ev;
    while (true) {
        auto now = std::chrono::high_resolution_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - start);
        if (elapsed.count()>=181) {
            SaveVars();
            start = now;
        }
        ssize_t n = read(fd, (void *)&ev, sizeof(ev));
        if (n ==(ssize_t)sizeof(ev)) {
            if (ev.type == EV_KEY) {
                if (ev.value == 1) {
                    switch (ev.code) {
                            case KEY_A:{c_a+=1;break;};
                            case KEY_B:{c_b+=1;break;};
                            case KEY_C:{c_c+=1;break;};
                            case KEY_D:{c_d+=1;break;};
                            case KEY_E:{c_e+=1;break;};
                            case KEY_F:{c_f+=1;break;};
                            case KEY_G:{c_g+=1;break;};
                            case KEY_H:{c_h+=1;break;};
                            case KEY_I:{c_i+=1;break;};
                            case KEY_J:{c_j+=1;break;};
                            case KEY_K:{c_k+=1;break;};
                            case KEY_L:{c_l+=1;break;};
                            case KEY_M:{c_m+=1;break;};
                            case KEY_N:{c_n+=1;break;};
                            case KEY_O:{c_o+=1;break;};
                            case KEY_P:{c_p+=1;break;};
                            case KEY_Q:{c_q+=1;break;};
                            case KEY_R:{c_r+=1;break;};
                            case KEY_S:{c_s+=1;break;};
                            case KEY_T:{c_t+=1;break;};
                            case KEY_U:{c_u+=1;break;};
                            case KEY_V:{c_v+=1;break;};
                            case KEY_W:{c_w+=1;break;};
                            case KEY_X:{c_x+=1;break;};
                            case KEY_Y:{c_y+=1;break;};
                            case KEY_Z:{c_z+=1;break;};
                            case KEY_1:{c_1+=1;break;};
                            case KEY_2:{c_2+=1;break;};
                            case KEY_3:{c_3+=1;break;};
                            case KEY_4:{c_4+=1;break;};
                            case KEY_5:{c_5+=1;break;};
                            case KEY_6:{c_6+=1;break;};
                            case KEY_7:{c_7+=1;break;};
                            case KEY_8:{c_8+=1;break;};
                            case KEY_9:{c_9+=1;break;};
                            case KEY_0:{c_0+=1;break;};
                            case KEY_SPACE:{c_space+=1;break;};
                            case KEY_ENTER:{c_enter+=1;break;};
                            default: ;
                    }
                }
            }
        }

    }
}