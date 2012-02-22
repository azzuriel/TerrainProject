#ifndef	TERRAINPROJECT_RGBA_H
#define TERRAINPROJECT_RGBA_H

/*
====================
rgba
====================
*/
class rgba
{
public:
	float red, green, blue, alpha;

	rgba();
	rgba( const float r, const float g, const float b );
	rgba( const float r, const float g, const float b, const float a );

	rgba&	operator=( const rgba& v );

	rgba	operator+( const rgba& v ) const;
	rgba	operator-( const rgba& v ) const;
	
	rgba	operator*( const rgba color ) const;
	rgba	operator/( const rgba color ) const;

	rgba	operator*( const float f ) const;
	rgba	operator/( const float f ) const;

	rgba&	operator+=( const rgba& v );
	rgba&	operator-=( const rgba& v );
	rgba&	operator*=( const float f );
	rgba&	operator/=( const float f );

	friend rgba operator*( const float f, const rgba color );
	
	void	Set( const float r, const float g, const float b, const float a );
	void	Lerp( const rgba& v, const rgba& w, const float delta );
};


// Creates zero vector
inline rgba::rgba(): red( 0.0f ), green( 0.0f ), blue( 0.0f ), alpha( 1.0f )
{}

inline rgba::rgba( const float r, const float g, const float b ): red( r ), green( g ), blue( b ), alpha( 1.0f )
{}

inline rgba::rgba( const float r, const float g, const float b, const float a): red( r ), green( g ), blue( b ), alpha( a )
{}

inline rgba& rgba::operator=( const rgba& color )
{
	red = color.red;
	green = color.green;
	blue = color.blue;
	alpha = color.alpha;

	return *this;
}

inline rgba rgba::operator+( const rgba& color ) const
{
	return rgba(
		this->red + color.red,
		this->green + color.green,
		this->blue + color.blue,
		this->alpha + color.alpha );
}

inline rgba rgba::operator-( const rgba& color ) const
{
	return rgba(
		red - color.red,
		green - color.green,
		blue - color.blue,
		alpha - color.alpha);
}

inline rgba rgba::operator*( const rgba color ) const
{
	rgba retColor;

	retColor.red = this->red * color.red;
	retColor.green = this->green * color.green;
	retColor.blue = this->blue * color.blue;
	retColor.alpha = this->alpha * color.alpha;

	return retColor;
}

inline rgba rgba::operator/( const rgba color ) const
{
	rgba retColor;

	retColor.red = this->red / color.red;
	retColor.green = this->green / color.green;
	retColor.blue = this->blue / color.blue;
	retColor.alpha = this->alpha / color.alpha;

	return retColor;
}

inline rgba rgba::operator*( const float f ) const
{
	return rgba(
		red * f,
		green * f,
		blue * f,
		alpha * f );
}

inline rgba rgba::operator/( const float f ) const
{
	float invf = 1.0f / f;

	return rgba(
		red * invf,
		green * invf,
		blue * invf,
		alpha * invf );
}

inline rgba& rgba::operator+=( const rgba& color )
{
	red += color.red;
	green += color.green;
	blue += color.blue;
	alpha += color.alpha;

	return *this;
}

inline rgba& rgba::operator-=( const rgba& color )
{
	red -= color.red;
	green -= color.green;
	blue -= color.blue;
	alpha -= color.alpha;

	return *this;
}


inline rgba& rgba::operator*=( const float f )
{
	red *= f;
	green *= f;
	blue *= f;
	alpha *= f;

	return *this;
}

inline rgba& rgba::operator/=( const float f )
{
	float invf = 1.0f / f;

	red *= invf;
	green *= invf;
	blue *= invf;
	alpha *= invf;

	return *this;
}

// friend operator overload
inline rgba operator*( const float f, const rgba color )
{
	return rgba(
		f * color.red,
		f * color.green,
		f * color.blue,
		f * color.alpha );
}

inline void rgba::Set( const float r, const float g, const float b, const float a )
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

inline void rgba::Lerp( const rgba& color1, const rgba& color2, const float delta )
{
	if( delta <= 0.0f )
		( *this ) = color1;
	else if( delta >= 1.0f )
		( *this ) = color2;
	else
		( *this ) = color1 + delta * ( color2 - color1 );
}

#endif