#include "Serializer.hpp"

int main(void)
{
	Data Input = {5, "Input"};
	Data *Output;
	uintptr_t Data_Serialized;

	std::cout << "Input structure:\n- value: " << Input.value << "\n- name: " << Input.name << std::endl;
	Data_Serialized = Serializer::serialize(&Input);
	std::cout << "Data_Serialized: " << Data_Serialized << std::endl;

	Output = Serializer::deserialize(Data_Serialized);
	std::cout << "Output structure:\n- value: " << Output->value << "\n- name: " << Output->name << std::endl;

	std::cout << "----------------------------\n" << std::endl;
	Input.name = "ChangedName";
	std::cout << "Input structure:\n- value: " << Input.value << "\n- name: " << Input.name << std::endl;	
	std::cout << "Output structure:\n- value: " << Output->value << "\n- name: " << Output->name << std::endl;
	return (0);
}