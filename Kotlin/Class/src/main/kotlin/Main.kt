import kotlin.properties.ReadWriteProperty
import kotlin.reflect.KProperty

// SUPER_CLASS SmartDevice ---------------------------------------------------------------------
// PRIMARY_CONSTRUCTOR
open class SmartDevice constructor(val name:String, val category:String){
    var deviceStatus = "off"
        protected set
    open val deviceType = "Unknown"
    // SECONDARY_CONSTRUCTOR
    constructor(name: String, category: String, statusCode: Int) : this(name,category){
        deviceStatus = when (statusCode){
            0 -> "off"
            1 -> "on"
            else -> "unknown"
        }
    }
    open fun turnOn(){
        deviceStatus = "on"
    }
    open fun turnOff():Int{
        if (deviceStatus == "off") return -1
        deviceStatus = "off"
        println("$name is off")
        return 0
    }
    fun printDeviceInfo(){
        println("Device name: $name, category: $category, type: $deviceType")
    }
}

// SUB_CLASS SmartTvDevice ---------------------------------------------------------------------
// Smart TV IS-A smart device. (IS-A relationship)
class SmartTvDevice(deviceName:String,deviceCategory:String): SmartDevice(name=deviceName, category=deviceCategory){
    /*
    private var speakerVolume = 100
    set(value){
        if (value in 0..100){
            field = value
        }
    }
    // Don't use the property name to get or set a value. For example, in the set() function, if you try to assign the value parameter to the speakerVolume property itself, the code enters an endless loop because the Kotlin runtime tries to update the value for the speakerVolume property, which triggers a call to the setter function repeatedly.
    private var channelNumber = 1
    set(value){
        if (value in 1..200){
            field = value
        }
    }
    */
    // using delegates
    private var speakerVolume by RangeRegulator(initialValue = 50, minValue = 0, maxValue = 100)
    private var channelNumber by RangeRegulator(initialValue = 1, minValue = 1, maxValue = 200)
    override val deviceType = "Smart Tv"
    override fun turnOn(){
        super.turnOn()
        println("$name is on, channel number : $channelNumber and volume : $speakerVolume")
    }
    override fun turnOff():Int{
        super.turnOff()
        return 0
    }
    fun increaseSpeakerVolume():Int{
        if (deviceStatus == "off") return -1
        speakerVolume++
        println("Speaker volume increased to $speakerVolume")
        return 0
    }
    fun decreaseSpeakerVolume():Int{
        if (deviceStatus == "off") return -1
        speakerVolume--
        println("Speaker volume decreased to $speakerVolume")
        return 0
    }
    fun nextChannel():Int{
        if (deviceStatus == "off") return -1
        channelNumber++
        println("Channel number increased to $channelNumber")
        return 0
    }
    fun previousChannel():Int{
        if (deviceStatus == "off") return -1
        channelNumber--
        println("Channel number decreased to $channelNumber")
        return 0
    }
}

// SUB_CLASS SmartLightDevice ---------------------------------------------------------------------
class SmartLightDevice(deviceName:String, deviceCategory:String) : SmartDevice(name=deviceName, category=deviceCategory){
    /*
    private var brightnessLevel = 100
    set(value){
        if (value in 0..100){
            field = value
        }
    }
    */
    private var brightnessLevel by RangeRegulator(initialValue = 50, minValue = 0, maxValue = 100)
    override fun turnOn(){
        super.turnOn()
        brightnessLevel = 50
        println("$name is on")
    }
    override val deviceType = "Smart Light"
    override fun turnOff():Int{
        super.turnOff()
        return 0
    }
    fun increaseBrightnessLevel():Int{
        if (deviceStatus == "off") return -1
        brightnessLevel++
        println("Brightness increased to $brightnessLevel")
        return 0
    }
    fun decreaseBrightnessLevel():Int{
        if (deviceStatus == "off") return -1
        brightnessLevel--
        println("Brightness decreased to $brightnessLevel")
        return 0
    }
}

// CLASS SmartHome ---------------------------------------------------------------------
// The SmartHome class HAS-A smart TV device and smart Light device. (HAS-A relationship)
class SmartHome(private val smartTvDevice:SmartTvDevice, private val
smartLightDevice:SmartLightDevice){
    private var deviceTurnOnCount = 0
    fun turnOnTv(){
        deviceTurnOnCount++
        smartTvDevice.turnOn()
    }
    fun turnOffTv():Int{
        if (smartTvDevice.turnOff() == -1) {
            println("Operation Failed! Device off!")
            return -1
        }
        deviceTurnOnCount--
        return 0
    }
    fun increaseTvVolume() {
        if (smartTvDevice.increaseSpeakerVolume() == -1) println("Operation Failed! Device off!")
    }
    fun decreaseTvVolume() {
        if (smartTvDevice.decreaseSpeakerVolume() == -1) println("Operation Failed! Device off!")
    }
    fun changeTvChannelToNext() {
        if (smartTvDevice.nextChannel() == -1) println("Operation Failed! Device off!")
    }
    fun changeTvChannelToPrevious() {
        if (smartTvDevice.previousChannel() == -1) println("Operation Failed! Device off!")
    }
    fun turnOnLight(){
        smartLightDevice.turnOn()
        deviceTurnOnCount++
    }
    fun turnOffLight(){
        deviceTurnOnCount--
        if (smartLightDevice.turnOff() == -1) println("Operation Failed! Device off!")
    }
    fun increaseLightBrightness() {
        if (smartLightDevice.increaseBrightnessLevel() == -1) println("Operation Failed! Device off!")
    }
    fun decreaseLightBrightness() {
        if (smartLightDevice.decreaseBrightnessLevel() == -1) println("Operation Failed! Device off!")
    }
}

// DELEGATE using interface ReadWriteProperty
class RangeRegulator(initialValue: Int, private val minValue: Int, private val maxValue: Int) : ReadWriteProperty <Any?,Int> {
    private var fieldData = initialValue // This property acts as the backing field for the
    // variable.
    // The KProperty is an interface that represents a declared property and lets you access the metadata on a delegated property. It's good to have high-level information about what the KProperty is.
    override fun getValue(thisRef: Any?, property: KProperty<*>): Int{
        return fieldData
    }
    override fun setValue(thisRef: Any?, property: KProperty<*>, value: Int){
        if (value in minValue..maxValue){
            fieldData = value
        }
    }
    // These methods act as the properties' getter and setter functions.
}

// MAIN_FUNCTION ---------------------------------------------------------------------
fun main() {
    val smartTvDevice = SmartTvDevice("Android Tv","Electronics")
    val smartLightDevice = SmartLightDevice("Smart Light","Electronics")
    val smartHome = SmartHome(smartTvDevice,smartLightDevice)
    /*
    println("${smartTvDevice.name} is ${smartTvDevice.deviceStatus}")
    println("------------------------------------------------------------------------")
    smartTvDevice.turnOn()
    smartTvDevice.turnOff()
    println("------------------------------------------------------------------------")
    */
    /*
    println("Volume is ${smartTvDevice.speakerVolume}")
    smartTvDevice.speakerVolume = 50
    println("Volume is ${smartTvDevice.speakerVolume}")
    smartTvDevice.speakerVolume = 150
    println("Volume is ${smartTvDevice.speakerVolume}")
    println("------------------------------------------------------------------------")
    */
    /*
    smartTvDevice.decreaseSpeakerVolume()
    smartTvDevice.increaseSpeakerVolume()
    smartTvDevice.increaseSpeakerVolume()
    println("------------------------------------------------------------------------")
    smartTvDevice.nextChannel()
    smartTvDevice.previousChannel()
    smartTvDevice.previousChannel()
    println("------------------------------------------------------------------------")
    println("------------------------------------------------------------------------")
    */
    /*
    smartLightDevice.decreaseBrightnessLevel()
    smartLightDevice.increaseBrightnessLevel()
    println("------------------------------------------------------------------------")
    println("------------------------------------------------------------------------")
    */
    /*
    smartHome.turnOnTv()
    println("------------------------------------------------------------------------")
    smartHome.decreaseTvVolume()
    smartHome.increaseTvVolume()
    println("------------------------------------------------------------------------")
    smartHome.changeTvChannelToNext()
    smartHome.changeTvChannelToPrevious()
    println("------------------------------------------------------------------------")
    smartHome.turnOnLight()
    println("------------------------------------------------------------------------")
    smartLightDevice.decreaseBrightnessLevel()
    smartLightDevice.increaseBrightnessLevel()
    println("------------------------------------------------------------------------")
    println("On device count : "+smartHome.deviceTurnOnCount)
    smartHome.turnOffTv()
    smartHome.turnOffLight()
    println("------------------------------------------------------------------------")
    println("------------------------------------------------------------------------")
	*/
    smartHome.turnOnTv()
    smartHome.turnOnLight()
    smartHome.increaseLightBrightness()
    smartHome.increaseTvVolume()
    smartHome.decreaseLightBrightness()
    smartHome.decreaseTvVolume()
    smartHome.changeTvChannelToNext()
    smartHome.changeTvChannelToPrevious()
    println("------------------------------------------------------------------------")
    println("------------------------------------------------------------------------")
    smartHome.turnOffTv()
    smartHome.turnOffLight()
    smartHome.increaseLightBrightness()
    smartHome.increaseTvVolume()
    smartHome.decreaseLightBrightness()
    smartHome.decreaseTvVolume()
    smartHome.changeTvChannelToNext()
    smartHome.changeTvChannelToPrevious()
}