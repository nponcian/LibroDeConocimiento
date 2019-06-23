#ifndef ROOT_ICONTROLLER_HPP
#define ROOT_ICONTROLLER_HPP

namespace root
{

class IController
{
public:
    virtual ~IController(){}
    virtual void execute() = 0;
};

} // namespace root

#endif // ROOT_ICONTROLLER_HPP
