#ifndef ENTITIYMANAGER_H
#define ENTITIYMANAGER_H

#include <vector>

#include "./Entity.h"
#include "./Component.h"

class EntityManager {
private:
	std::vector<Entity*> entities;

public:
	void ClearData();
	void Update(float deltaTime);
	void Render();
	bool HasNoEntities();
	Entity& AddEntity(std::string entityName);
	std::vector<Entity*> GetEntities() const;
	unsigned int GetEntityCount();
};

#endif
