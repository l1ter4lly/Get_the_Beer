// ***************************************************************************
// vector
// ***************************************************************************

#pragma once

// ---------------------------------------------------------------------------
// data structure describing a single vector

struct vector_t
{
	int y;		// y coordinate byte
	int x;		// x coordinate byte
};

// ---------------------------------------------------------------------------
// vector drawing modes for packet style vector lists

enum mode_t
{
	MOVE = 0,
	STOP = 1,
	DRAW = 255
};

// ---------------------------------------------------------------------------
// data structure describing a single extended vector

struct packet_t
{
	enum mode_t mode;			// drawing mode
	struct vector_t vector;		// relative vector;
};

// ---------------------------------------------------------------------------
// vector list types

enum list_t
{
	PACKET = 0,		// packet list: each vector has its own drawing mode
	DIFFY = 1,		// vector list: all vectors are drawn
	DUFFY = 2		// vector list: first vector is moved, all others are drawn
};

// ---------------------------------------------------------------------------
// data structure describing a vector list

struct vector_list_t
{
	enum list_t type;	// type of vector list
	unsigned int size;	// length of vector list
	void* vectors;		// generic pointer to array of vectors or packets
};

// ***************************************************************************
// end of file
// ***************************************************************************
