#include <cstring>
#include <iostream>

#define ALPHANUM "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

struct Data
{
	std::string		s1;
	int				n;
	std::string		s2;
};

void *serialize()
{
	int		i;
	char	tmp[9] = {0};
	char	*data = new char[20];

	for (i = 0; i < 8; i++)
		data[i] = ALPHANUM[std::rand() % 62];
	for (i = 8; i < 12; i++)
		data[i] = std::rand() % 256;
	for (i = 12; i < 20; i++)
		data[i] = ALPHANUM[std::rand() % 62];
	std::cout << "Serialized: " << std::endl;
	std::cout << strncpy(tmp, data, 8) << std::endl;
	std::cout << static_cast<int>(data[8]) << std::endl;
	std::cout << strncpy(tmp, data + 12, 8) << std::endl;
	return (reinterpret_cast<void*>(data));
}

Data *deserialize(void *ptr)
{
	Data	*data = new Data;
	char	tmp[9] = {0};
	char	*input = reinterpret_cast<char*>(ptr);

	data->s1 = strncpy(tmp, input, 8);
	data->n = input[8];
	data->s2 = strncpy(tmp, input + 12, 8);
	return (data);
}

int main()
{
	std::srand(time(NULL));

	void	*ser = serialize();
	Data	*des = deserialize(ser);

	std::cout << "Data:" << std::endl;
	std::cout << des->s1 << std::endl;
	std::cout << des->n << std::endl;
	std::cout << des->s2 << std::endl;
	return (0);
}
