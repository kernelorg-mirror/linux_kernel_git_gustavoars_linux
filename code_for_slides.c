

 	struct bounded_flex_struct {
                ...
                size_t elements;
                struct foo flex_array[] __attribute__((__element_count__(elements)));
        };







	struct trailing {
		...
		some members;
		...
		char happy_array[10];
	};






	struct ancient {
		...
		size_t count;
		struct foo anxious_array[1];
	};





	struct old {
		...
		size_t count;
		struct foo unhappy_array[0];
	};





	struct modern {
		...
		size_t count;
		struct foo happy_array[];
	};






	struct flex_struct {
		...
		size_t count;
		struct foo flex_array[];
	};






   sizeof(flex_struct->one_element_array) == size-of-element-type

   sizeof(flex_struct->zero_length_array) == 0
   
   sizeof(flex_struct->flex_array_member) == ? /* Error */





   __builtin_object_size(flex_struct->one_element_array, 1) == -1
   
   __builtin_object_size(flex_struct->zero_length_array, 1) == -1
   
   __builtin_object_size(flex_struct->flex_array_member, 1) == -1

   sizeof(flex_struct->one_element_array) == size-of-element-type
   sizeof(flex_struct->zero_length_array) == 0
   sizeof(flex_struct->flex_array_member) == ? /* Error */

   __builtin_object_size(any_struct->any_trailing_array, 1) == -1





   __builtin_object_size(flex_struct->one_element_array, 1) == -1
   __builtin_object_size(flex_struct->zero_length_array, 1) == -1
   __builtin_object_size(flex_struct->flex_array_member, 1) == -1

   sizeof(flex_struct->one_element_array) == size-of-element-type
   sizeof(flex_struct->zero_length_array) == 0
   sizeof(flex_struct->flex_array_member) == ? /* Error */

   __builtin_object_size(any_struct->any_trailing_array, 1) == -1




   __builtin_object_size(flex_struct->one_element_array, 1) == -1
   __builtin_object_size(flex_struct->zero_length_array, 1) == -1
   __builtin_object_size(flex_struct->flex_array_member, 1) == -1

   sizeof(flex_struct->one_element_array) == size-of-element-type
   sizeof(flex_struct->zero_length_array) == 0
   sizeof(flex_struct->flex_array_member) == ? /* Error */







   __builtin_object_size(flex_struct->one_element_array, 1) == -1
   __builtin_object_size(flex_struct->zero_length_array, 1) == -1
   __builtin_object_size(flex_struct->flex_array_member, 1) == -1











	struct flex_struct {
		...
		size_t elements;
		struct foo flex_array[] __attribute__((__element_count__(elements)));
	};








