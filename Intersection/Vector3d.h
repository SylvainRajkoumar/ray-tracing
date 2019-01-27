#ifndef __VECTOR3D_H
#define __VECTOR3D_H

#include <math.h>

class CRTVector
{
	public:

		CRTVector (float fX=0.0f,float fY=0.0f,float fZ=0.0f)
			:	x	(fX),
				y	(fY),
				z	(fZ)
		{
		}

		CRTVector (const CRTVector &vVector)
			:	x	(vVector.x),
				y	(vVector.y),
				z	(vVector.z)
		{
		}

		// Operators
		
		CRTVector operator = (const CRTVector &v)
		{
			x=v.x ;
			y=v.y ;
			z=v.z ;
			return *this ;
		}
		
		CRTVector operator + (const CRTVector &v) const
		{
			return CRTVector (x+v.x,y+v.y,z+v.z) ;
		}
		
		CRTVector operator - (const CRTVector &v) const
		{
			return CRTVector (x-v.x,y-v.y,z-v.z) ;
		}

		CRTVector operator - ()                  const
		{
			return CRTVector (-x,-y,-z) ;
		}
		
		CRTVector operator * (float k)           const
		{
			return CRTVector (k*x,k*y,k*z) ;
		}
		
		CRTVector operator / (float k)           const
		{
			return CRTVector (x/k,y/k,z/k) ;
		}
		
		float Dot (const CRTVector &v) const
		{
			return ( (x*v.x) + (y*v.y) + (z*v.z) ) ;
		}
		
		CRTVector Cross (const CRTVector &v) const
		{
			return CRTVector (y*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x) ;
		}
		
		CRTVector & operator += (const CRTVector & v)
		{
			x+=v.x;
			y+=v.y;
			z+=v.z;
			return *this;
		}

		CRTVector & operator /= (float fFactor)
		{
			x/=fFactor ;
			y/=fFactor ;
			z/=fFactor ;
			return *this;
		}

		float GetLength ()
		{
			return ( (float) sqrt (x*x+y*y+z*z) ) ;
		}
		
		void Normalize ()
		{
			float fLength=GetLength ();
			
			if (fLength>0)
			{
				x/=fLength;
				y/=fLength;
				z/=fLength;
			}
		}

		CRTVector Unit ()
		{
			CRTVector v(*this) ;
			v.Normalize () ;
			return v ;
		}

		struct
		{
			float x , y , z ;
		};
};

#endif
