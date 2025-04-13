#pragma once



enum platform_state_t
{
	MOBILE,
	STATIC,
};

enum platform_size_t
{
	MIDDLE,
	LARGE,
};
// ---------------------------------------------------------------------------

struct platform_t
{
	enum platform_state_t state;
	enum platform_size_t size;
	
	int y;
	int x;

	int speed_y;
	int speed_x;
	
	unsigned int max_travel_dist;
	unsigned int travelled_dist;

};


void platform_update(struct platform_t* p);

void platform_draw(struct platform_t* p);
int platform_check(struct platform_t* p);
