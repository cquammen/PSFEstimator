/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile: itkGibsonLanniPSFImageSource.h,v $
  Language:  C++
  Date:      $Date: 2009/07/08 18:55:48 $
  Version:   $Revision: 1.2 $

  Copyright (c) Insight Software Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

  Portions of this code are covered under the VTK copyright.
  See VTKCopyright.txt or http://www.kitware.com/VTKCopyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef __itkGibsonLanniPSFImageSource_h
#define __itkGibsonLanniPSFImageSource_h

#include <complex.h>

#include "itkImageSource.h"
#include "itkNumericTraits.h"

namespace itk
{

/** \class GibsonLanniPSFImageSource
 * \brief Generate a synthetic point-spread function according to the
 * Gibson-Lanni model.
 *
 * The Gibson-Lanni point-spread function model takes into account optical
 * path differences from the design conditions of an objective in a
 * widefield fluorescence microscope. This image source generates images
 * according to this model. IMPORTANT: Please pay attention to the units
 * each method expects. Some take nanometers, some take micrometers, and some
 * take millimeters.
 *
 * \ingroup DataSources Multithreaded
 */
template <typename TOutputImage>
class ITK_EXPORT GibsonLanniPSFImageSource : public ImageSource<TOutputImage>
{
public:
  /** Standard class typedefs. */
  typedef GibsonLanniPSFImageSource         Self;
  typedef ImageSource<TOutputImage> Superclass;
  typedef SmartPointer<Self>        Pointer;
  typedef SmartPointer<const Self>  ConstPointer;

  /** Typedef for the output image PixelType. */
  typedef typename TOutputImage::PixelType OutputImagePixelType;

  /** Typedef to describe the output image region type. */
  typedef typename TOutputImage::RegionType OutputImageRegionType;

  /** Typedef for complex type. */
  typedef complex<OutputImagePixelType> complex_t;

  /** Run-time type information (and related methods). */
  itkTypeMacro(GibsonLanniPSFImageSource,ImageSource);

  /** Method for creation through the object factory. */
  itkNewMacro(Self);
  
  /** Specify the size of the output image. */
  itkSetVectorMacro(Size,unsigned long,TOutputImage::ImageDimension);

  /** Get the size of the output image. */
  itkGetVectorMacro(Size,unsigned long,TOutputImage::ImageDimension);
  
  /** Specify the spacing of the output image (in nanometers). */
  itkSetVectorMacro(Spacing,float,TOutputImage::ImageDimension);

  /** Get the spacing of the output image (in nanometers). */
  itkGetVectorMacro(Spacing,float,TOutputImage::ImageDimension);

  /** Specify the origin of the output image (in nanometers). */
  itkSetVectorMacro(Origin,float,TOutputImage::ImageDimension);

  /** Get the origin of the output image (in nanometers). */
  itkGetVectorMacro(Origin,float,TOutputImage::ImageDimension);
  
  /** Specify the emission wavelength (in nanometers). */
  itkSetMacro(EmissionWavelength,float);

  /** Get the emission wavelength (in nanometers). */
  itkGetMacro(EmissionWavelength,float);

  /** Specify the numerical aperture (unitless). */
  itkSetMacro(NumericalAperture,float);

  /** Get the numerical aperture (unitless). */
  itkGetMacro(NumericalAperture,float);

  /** Specify the magnification (unitless). */
  itkSetMacro(Magnification,float);

  /** Get the magnification (unitless). */
  itkGetMacro(Magnification,float);

  /** Specify the mechanical tube length (in millimeters). */
  itkSetMacro(MechanicalTubeLength,float);
  
  /** Get the mechanical tube length (in millimeters). */
  itkGetMacro(MechanicalTubeLength,float);

  /** Specify the design cover slip refractive index (unitless). */
  itkSetMacro(DesignCoverSlipRefractiveIndex,float);

  /** Get the design cover slip refractive index (unitless). */
  itkGetMacro(DesignCoverSlipRefractiveIndex,float);

  /** Specify the actual cover slip refractive index (unitless). */
  itkSetMacro(ActualCoverSlipRefractiveIndex,float);

  /** Get the actual cover slip refractive index (unitless). */
  itkGetMacro(ActualCoverSlipRefractiveIndex,float);

  /** Specify the design cover slip thickness (in micrometers). */
  itkSetMacro(DesignCoverSlipThickness,float);

  /** Get the design cover slip thickness (in micrometers). */
  itkGetMacro(DesignCoverSlipThickness,float);

  /** Specify the actual cover slip thickness (in micrometers). */
  itkSetMacro(ActualCoverSlipThickness,float);

  /** Get the actual cover slip thickness (in micrometers). */
  itkGetMacro(ActualCoverSlipThickness,float);

  /** Specify the design immersion oil refractive index (unitless). */
  itkSetMacro(DesignImmersionOilRefractiveIndex,float);

  /** Get the design immersion oil refractive index (unitless). */
  itkGetMacro(DesignImmersionOilRefractiveIndex,float);

  /** Specify the actual immersion oil refractive index (unitless). */
  itkSetMacro(ActualImmersionOilRefractiveIndex,float);

  /** Get the actual immersion oil refractive index (unitless). */
  itkGetMacro(ActualImmersionOilRefractiveIndex,float);

  /** Specify the design immersion oil thickness (in micrometers). */
  itkSetMacro(DesignImmersionOilThickness,float);

  /** Get the actual immersion oil refractive index (in micrometers). */
  itkGetMacro(DesignImmersionOilThickness,float);

  /** Specify the design specimen layer refractive index (unitless). */
  itkSetMacro(DesignSpecimenLayerRefractiveIndex,float);

  /** Get the design specimen layer refractive index (unitless). */
  itkGetMacro(DesignSpecimenLayerRefractiveIndex,float);

  /** Specify the actual specimen layer refractive index (unitless). */
  itkSetMacro(ActualSpecimenLayerRefractiveIndex,float);

  /** Get the actual specimen layer refractive index (unitless). */
  itkGetMacro(ActualSpecimenLayerRefractiveIndex,float);

  /** Specify the actual point source depth in the specimen layer (in nanometers). */
  itkSetMacro(ActualPointSourceDepthInSpecimenLayer,float);

  /** Get the actual point source depth in the specimen layer (in nanometers). */
  itkGetMacro(ActualPointSourceDepthInSpecimenLayer,float);

  /** Specify the design distance from the back focal plane to the detector (in millimeters). */
  itkSetMacro(DesignDistanceFromBackFocalPlaneToDetector,float);

  /** Get the design distance from the back focal plane to the detector (in millimeters). */
  itkGetMacro(DesignDistanceFromBackFocalPlaneToDetector,float);

  /** Specify the actual distance from the back focal plane to the detector (in millimeters). */
  itkSetMacro(ActualDistanceFromBackFocalPlaneToDetector,float);

  /** Get the actual distance from the back focal plane to the detector (in millimeters). */
  itkGetMacro(ActualDistanceFromBackFocalPlaneToDetector,float);

  static float BesselFunctionZeroOrderFirstKind(float x);

protected:
  GibsonLanniPSFImageSource();
  ~GibsonLanniPSFImageSource();
  void PrintSelf(std::ostream& os, Indent indent) const;
  
  virtual void 
  ThreadedGenerateData(const OutputImageRegionType& 
                       outputRegionForThread, int threadId );
  virtual void GenerateOutputInformation();

  complex_t OPD_term(float NA, float n_oil, float rho, float n, float t);

  complex_t OPD(float rho, float delta_z, float a);
  
  void PrecomputeOPDTerms(complex_t* opdCache, float z_o);

  complex_t IntegralTerm(complex_t* opdCache, float K, float a, float z_d,
			 int rhoIndex, float h, float r_o, float z_o);

  float ComputePixelValue(complex_t* opdCache,
			  typename TOutputImage::PointType& point);

private:
  GibsonLanniPSFImageSource(const GibsonLanniPSFImageSource&); //purposely not implemented
  void operator=(const GibsonLanniPSFImageSource&); //purposely not implemented

  unsigned long *m_Size;    //size of the output image
  float         *m_Spacing; //spacing
  float         *m_Origin;  //origin

  /** Point-spread function model parameters. */
  float m_EmissionWavelength;
  float m_NumericalAperture;
  float m_Magnification;
  float m_MechanicalTubeLength;
  float m_DesignCoverSlipRefractiveIndex;
  float m_ActualCoverSlipRefractiveIndex;
  float m_DesignCoverSlipThickness;
  float m_ActualCoverSlipThickness;
  float m_DesignImmersionOilRefractiveIndex;
  float m_ActualImmersionOilRefractiveIndex;
  float m_DesignImmersionOilThickness;
  float m_DesignSpecimenLayerRefractiveIndex;
  float m_ActualSpecimenLayerRefractiveIndex;
  float m_ActualPointSourceDepthInSpecimenLayer;
  float m_DesignDistanceFromBackFocalPlaneToDetector;
  float m_ActualDistanceFromBackFocalPlaneToDetector;

};

} // end namespace itk

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkGibsonLanniPSFImageSource.cxx"
#endif

#endif
