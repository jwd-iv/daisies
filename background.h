struct SkyComponent : public tiny::component
{
  rkMetaHandle(SkyComponent);
};

struct CloudComponent : public tiny::component
{
  rkMetaHandle(CloudComponent);
};

struct GroundComponent : public tiny::component
{
  rkMetaHandle(GroundComponent);
};

struct BackgroundManager : public tiny::job
{
  // Inherited via job
  virtual void start();
  virtual void update(float dt);
  virtual bool done() const;
  virtual void finish();


  rkMetaHook(BackgroundManager);
};
