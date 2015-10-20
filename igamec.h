#pragma once

class IGameComponent
{
public:
	virtual ~IGameComponent() {}
	virtual void init() {};
	virtual void update() {};
	virtual void render() {};
};