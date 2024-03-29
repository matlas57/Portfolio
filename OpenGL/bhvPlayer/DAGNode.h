//Matan Atlas
//260943621
#pragma once
#ifndef DAGNODE_H
#define DAGNODE_H

#include <string>
#include <vector>
#include <memory>
#include "GLSL.h"
#include "Shape.h"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Program;
class MatrixStack;


/**
 * This class manages nodes for a character skeleton specified by a bvh file.
 * TODO: add to this class as needed!
 */
class DAGNode
{
public:
	DAGNode();
	virtual ~DAGNode();	
	void init();
	void DAGNode::traverseAndReset(DAGNode root);
	// Draws the node and its children.  TODO: modify this method signature if needed!
	void draw(const std::shared_ptr<Program> prog, std::shared_ptr<Shape> shape, std::shared_ptr<Shape> cube, const std::shared_ptr<Program> prog2, GLuint vao, const std::shared_ptr<MatrixStack> MV, const std::shared_ptr<MatrixStack> P, float* frameData, DAGNode root, int currentFrame, int totalChannels) const;
	bool visited;
	
	// name of this node (useful for debugging)
	std::string name;
	// translational offset of this node from its parent
	glm::fvec3 offset;
	// channel names, each will be one of Xposition Yposition Zposition Xrotation Yrotation Zrotation
	std::vector<std::string> channels;
	// parent of this node, or NULL if this node is the root
	DAGNode* parent;
	// children of this node
	std::vector <DAGNode*> children;
	// start index from which this node's channel data can be read from a frame of motion capture data
	int channelDataStartIndex;

private:
};

#endif
