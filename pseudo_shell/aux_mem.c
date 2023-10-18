#include "custom_header.h"

/**
 * custom_memcpy - Copies information between void pointers.
 *
 * @dest: Destination pointer.
 * @src: Source pointer.
 * @size: Size of the destination pointer.
 * Return: No return.
 */
void custom_memcpy(void *dest, const void *src, unsigned int size)
{
	char *char_dest = (char *)dest;
	char *char_src = (char *)src;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_dest[i] = char_src[i];
}

/**
 * custom_realloc - Reallocates a memory block.
 *
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 * Return: Pointer to the reallocated memory block.
 */
void *custom_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (custom_malloc(new_size));

	if (new_size == 0)
	{
		custom_free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = custom_malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size < old_size)
		custom_memcpy(new_ptr, ptr, new_size);
	else
		custom_memcpy(new_ptr, ptr, old_size);

	custom_free(ptr);
	return (new_ptr);
}

/**
 * custom_realloc_double_pointer - Reallocates a memory block of a double pointer.
 *
 * @ptr: Double pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 * Return: Pointer to the reallocated memory block.
 */
char **custom_realloc_double_pointer(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **new_ptr;
	unsigned int i;

	if (ptr == NULL)
		return (custom_malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	new_ptr = custom_malloc(sizeof(char *) * new_size);
	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		new_ptr[i] = ptr[i];

	custom_free(ptr);

	return (new_ptr);
}
