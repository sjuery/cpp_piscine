#include <iostream>
#include <string>
#include <random>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

void	RSGenerator(std::string &s)
{
	std::string string = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 8; ++i) {
        s[i] = string[rand()%string.length()];
    }
}

void *serialize() {
	std::string s1(9, '\0');
    std::string s2(9, '\0');
    int n = rand()%10000;
    RSGenerator(s1);
    RSGenerator(s2);

    Data *data = new Data();
    data->s1 = s1;
    data->n = n;
    data->s2 = s2;
    std::cout << "Genrerated the following serialized data:\n[S1 = " << s1 << "]\n[N = " << n << "]\n[S2 = " << s2 << "]" << std::endl;
    return static_cast<void *>(data);
}

Data *deserialize(void *raw) {
    return static_cast<Data *>(raw);
}

int main()
{
    srand(time(0));
    Data *data = deserialize(serialize());
    std::cout << "After deserialization we got:\n[S1 = " << data->s1 << "]\n[N = " << data->n << "]\n[S2 = " << data->s2 << "]" << std::endl;
    return 0;
}
