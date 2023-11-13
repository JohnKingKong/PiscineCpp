#pragma once

#include <stdint.h>
#include <iostream>

uintptr_t	serialize(Data* ptr);

Data	*deserialize(uintptr_t raw);
