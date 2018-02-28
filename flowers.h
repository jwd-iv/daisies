struct SeedComponent : public tiny::component
{
  tiny::guid sprite;

  rkMetaHandle(SeedComponent);
};

struct FlowerComponent : public tiny::component
{
  tiny::guid sprite;

  rkMetaHandle(FlowerComponent);
};

struct FlowerManager : public tiny::job
{
  void SpawnFlower();
  void UpdateSeedDrift();

  // Inherited via job
  virtual void start();
  virtual void update(float dt);
  virtual bool done() const;
  virtual void finish();

  rkMetaHook(FlowerManager);
};
