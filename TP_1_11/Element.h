#pragma once
template <typename T>
struct Element
{
	T data;
	Element* prev;
};