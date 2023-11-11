# HashingTechnique
As defined, linear search and binary search are useful data structures for
searching.The time taken for searching in linear search is O(n), while in a binary search O(log₂(n)), but
what would you do if you want the shorter time?
This repository provides an explanation of everything related to Hashing Technique
## Table of contents
- [Hashing Technique Overview](#HashingTechniqueOverview)
- [Ideal Hashing](#IdealHashing)
- [Collision](#collision)
- [Chaining](#chaining)
- [Linear Probing](#LinearProbing)
- [Quadratic Probing](#QuadraticProbing)
- [Double Hashing](#DoubleHashing)
## Hashing Technique Overview
In general, Hashing is a technique in computer science that uses a hash function to convert 
data(such as a key or input) into a fixed-size string of characters, known as a hash code.The
goal is to quickly map data to a specific location in a data structure, often for efficient retrieval and storage.
Hashing is commonly used in structures like hash tables, where the hash code determines the index or location 
where data is stored or retrieved.
More simplified, The hash function gives us the index and we store a key at that index.Using that hash function, we will 
map the keys on a hash table.There are four types of mappings: one-to-one, one-to-many, many-to-one and many-to-many but
the hash function supports only two types of mappings that is one-to-one or many-to-one.
## Ideal Hashing
If we map a key to the index equal to it in a hash table, then the size of the hash table is 
equal to the maximum key among keys plus one and the hash function is h(x)=x which is called ideal hashing 
because the time taken for searching, storing, or deleting an element is constant.Just use the hash function
and store the value there in the hash table and use the hash function to retrieve the value, so the time is constant.
Despite the usefulness of ideal hashing in storing the elements, its drawback is that the space is very huge, it means that 
if the maximum key is a very big numbet, then the size of the hash table will be very huge and there will be unnecessary 
locations that we didn't use.The responsible for this drawback is the hash function and if you want to reduce the space, you
have to modify it.We can make it a modulus function(h(x)=x%10).The benefit of the mod function is that the size of the hash table 
will be limited but it has a drawback, more than one key may be mapped at the same index(many-to-one mapping).
## Collision
When two keys hash to the same index, we call it as "Collision".There are some solutions to avoid collision like open hashing 
and closed hashing.Open hashing includes chaining and closed hashing(open addressing)includes linear probing, quadratic probing
and double hashing.
## Chaining
For resolving collision, chaining is one of the methods and it comes under open hashing.We can apply it using linked list data structure by creating a linked list for every location in the hash table so that if there is more than one key that must be inserted in the same location, we can insert every key in its own node in the linked list.
-‌ Search:
 Here's a step-by-step explanation of how the search process works in chaining:
1.compute the hash value for the key using the hash function.
2.go to that value in hash table.
3.search for the key in the linked list.
- Analysis:
   Analysis of hashing is always done based on loading factor. 
L=n/s, where L is loading factor, n is number of keys and s is the size of the hash table.
- for ex, L=100/10=10, We assume that at each location there are 10 keys(nodes), our assumption may be wrong but we are assuming
  this or actually we are expecting this.
  Avg.successful search -> t=1+loading factor/2, where 1= the time to reach a location in the hash table(constant time)and loading 
   factor/2 is equal to the average time to search the key in the linked list.
  Avg.unsuccessful search -> 1+loading factor
Note:it is loading factor not loading factor/2 because we wil search for the key in all nodes of the linked list.
# Linear Probing
 Linear Probing comes under closed hashing, We insert a key into the hash table using the hash function.
 When a conclusion occurs, the algorithm searches for the next available slot linearly until an empty slot is found.
  - Search:
   In searching, empty place found means element is not there.
   Here's a step-by-step explanation of how the search process works in linear probing:
    1.Compute the hash value for the key using the hash function.
    2.Check if the element is present at the computed hashed index, the search is successful.
    3.If the element is not found at the hashed index, move to the next index.
    4.Repeat this process until you either find the key or encounter an empty slot.If you reach an empty slot during the search,it 
     indicates that the key isn't present in the hash table.
  - Delete:
   Here's a step-by-step explanation of how the delete process works in linear probing:
    1.compute the hash value for the key using the hash function.
    2.go to that particular index.
    3.start searching then delete it.
    4.after deletion, you have to shift the next keys
   Note:you have to check whether the next key belongs to that index or the next index before shifting it.
  - Analysis:
   As we mentioned before, analysis of hashing is done based on loading factor, it's not done based on number of elements.
   In linear probing, loading factor should be less than or equal to 0.5.It means that whatever the size of the hash table, at the most, 
   it can be half filled.Keeping a significant portion of the hash table vacant is beneficial for the efficiency of the algorithm.The 
   reason for leaving some space vacant is to avoid clustering, which occurs when consecutive slots are filled, making it more likely 
   for further collisions to happen in close proximity.
  Avg.successful search-> t= 1/L ln(1/1-L), where L is loading factor.
  Avg.unsuccessful search -> t=1/1-L, where L is loading factor. 
 ‌ - Drawback of linear probing 
   1.you have to keep half of the hash table vacant 
   2. a lot of keys may be accumulating at one place and forming a cluster, so linear probing has a problem of primary clustering of 
   keys that is a group of keys together at one place.
## Quadratic Probing
  It's also comes under closed hashing.If there's a collision, we try to store an element at some free space in the hash table.The hash 
  table whatever the space is given, we try to utilize that same space.
  In linear probing, there was a problem of clustering of elements that group of elements were forming a single block, so to avoid that, 
  we have introduced quadratic probing.Instead of searching for the next slot linearly, quadratic probing uses a quadratic function to 
  determine the next slot,the function is often of the form: h'(x)=(h(x)+f(i))%10, where f(i)= i^2, i=0,1,2,....
  In quadratic probing, we compute the hash value for the key using the hash function(h(x)), compute the h'(x)
  and then go to that index in the hash table.
 Avg.successful search-> -loge(1-L)/L, where L is loading factor.
 Avg.unsuccessful search-> 1/1-L, where L is loading factor.
## Double Hashing
 The idea here is that we will have two hash function, one is the basic hash function.Then if there's a collision, the another hash 
 function will help us to remove it.Second hash function is having two desired properties.One is it should never give a result zero
 (it shouldn't give index 0), and the second thing it should try to probe all the locations.Means that whenever there's a collision, it 
 shouldn't give the indices in the same pattern, it should give different indices such that all the locations are utilized.
 h1(x)=x%10
 h2(x)=R-(x%R), where R is a primary number that are smaller than the hash table.
 We will use regular hash function (h1(x)) if there's is a collision, then we will try to use this modified hash function (h'(x))
Note:Double hashing function gives us different locations for different keys.

