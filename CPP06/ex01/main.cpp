#include "Serializer.hpp"

int main(void)
{
	Data Input = {5, "Input"};
	Data* OriginalPointer = &Input;
	Data *OutputPointer;
	uintptr_t Data_Serialized;

	std::cout << "OrginalPointer: " << OriginalPointer << std::endl;

	Data_Serialized = Serializer::serialize(OriginalPointer);
	std::cout << "Data_Serialized: " << Data_Serialized << std::endl;

	OutputPointer = Serializer::deserialize(Data_Serialized);
	std::cout << "OutputPointer: " << OutputPointer << std::endl;

	if (OutputPointer != OriginalPointer)
		std::cout << "ERROR" << std::endl;
	
	return (0);
}