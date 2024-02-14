#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "ray.h"
#include "hit.h"
#include "vectors.h"

// ====================================================================
// ====================================================================

// You will extend this class in later assignments

class Material {

public:

  // CONSTRUCTORS & DESTRUCTOR
  explicit Material(const Vec3f &d_color) { _diffuseColor = d_color; }

    Material();

    virtual ~Material() = default;

  // ACCESSORS
  virtual Vec3f getDiffuseColor() const { return _diffuseColor; }
  virtual Vec3f getSpecularColor()        const=0;
  virtual Vec3f getReflectiveColor()      const=0;
  virtual Vec3f getTransparentColor()     const=0;
  virtual float getindexofrefraction()    const=0;

  virtual void glSetMaterial() const = 0;
  virtual Vec3f Shade(const Ray &ray, const Hit &hit, const Vec3f &dirToLight, const Vec3f &lightColor) const = 0;

protected:

  // REPRESENTATION
  Vec3f _diffuseColor;
  
};

// ====================================================================
// ====================================================================

class PhongMaterial : public Material {
    Vec3f _specularColor;
    float _exponent;
    Vec3f _reflectiveColor;
    Vec3f _transparentColor;
    float _indexOfRefraction;

public:
    PhongMaterial(const Vec3f &diffuseColor,
                                 const Vec3f &specularColor,
                                 float exponent,
                                 const Vec3f &reflectiveColor,
                                 const Vec3f &transparentColor,
                                 float indexOfRefraction);

    Vec3f getSpecularColor() const { return _specularColor; }
    Vec3f getReflectiveColor() const {return _reflectiveColor;}
    Vec3f getTransparentColor() const {return _transparentColor;}
    float getindexofrefraction() const {return _indexOfRefraction;}

    void glSetMaterial() const override;
    Vec3f Shade(const Ray &ray, const Hit &hit, const Vec3f &dirToLight, const Vec3f &lightColor) const override;
};

#endif
