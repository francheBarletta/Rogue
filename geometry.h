#pragma once

// This abstract data structure
// holds geometry in "world coordinates"
// so both the position, orientation and size are known
typedef struct geometry_t* Geometry;

/*
 * TODO: use a central allocator.
 * you own this new geometry
 * be sure to destroy it when you are done!
 */

// Construction
Geometry xy_to_geometry(int x, int y);
Geometry rec_to_geometry(int xleft, int ytop, int xright, int ybottom);
// Geometry poly_to_geometry(int *xs, int *ys);
Geometry unite_two(Geometry g1, Geometry g2);
// Geometry unite_many(Geometry *gs);
Geometry clone(Geometry g);

// Checks
bool intersects(Geometry first, Geometry second);
bool is_inside(Geometry big, Geometry small);

// Transformations
void translate_inplace(int dx, int dy, Geometry g);
Geometry translate(int dx, int dy, Geometry g);
