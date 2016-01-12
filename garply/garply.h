#ifndef GARPLY_H_

class Garply
{
private:
    static const int version_major;
    static const int version_minor;

public:
    Garply();
    int get_version() const;
    int garplinate() const;
};

#endif // GARPLY_H_
