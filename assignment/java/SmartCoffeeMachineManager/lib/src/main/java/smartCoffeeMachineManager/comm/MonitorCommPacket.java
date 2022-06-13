package smartCoffeeMachineManager.comm;

import com.fasterxml.jackson.annotation.JsonProperty;

public class MonitorCommPacket implements CommPacket {

	@JsonProperty("mode")
	private String mode;
	@JsonProperty("tea")
	private int tea;
	@JsonProperty("coffee")
	private int coffee;
	@JsonProperty("chocolate")
	private int chocolate;
	@JsonProperty("sugar")
	private int sugar;
	@JsonProperty("nTests")
	private int nTests;
	
	@Override
	public String getContent() {
		StringBuilder sb = new StringBuilder();
		sb.append(MonitorCommPacket.class.getName()).append('@').append(Integer.toHexString(System.identityHashCode(this))).append('[');
		sb.append("mode");
		sb.append('=');
		sb.append(this.mode);
		sb.append(',');
		sb.append("tea");
		sb.append('=');
		sb.append(String.valueOf(this.tea));
		sb.append(',');
		sb.append("coffee");
		sb.append('=');
		sb.append(String.valueOf(this.coffee));
		sb.append(',');
		sb.append("chocolate");
		sb.append('=');
		sb.append(String.valueOf(this.chocolate));
		sb.append(',');
		sb.append("sugar");
		sb.append('=');
		sb.append(String.valueOf(this.sugar));
		sb.append(',');
		sb.append("nTests");
		sb.append('=');
		sb.append(String.valueOf(this.nTests));
		sb.append("]");
		return sb.toString();
	}

	@JsonProperty("mode")
	public String getMode() {
	return mode;
	}

	@JsonProperty("mode")
	public void setMode(String mode) {
	this.mode = mode;
	}

	@JsonProperty("tea")
	public Integer getTea() {
	return tea;
	}

	@JsonProperty("tea")
	public void setTea(Integer tea) {
	this.tea = tea;
	}

	@JsonProperty("coffee")
	public Integer getCoffee() {
	return coffee;
	}

	@JsonProperty("coffee")
	public void setCoffee(Integer coffee) {
	this.coffee = coffee;
	}

	@JsonProperty("chocolate")
	public Integer getChocolate() {
	return chocolate;
	}

	@JsonProperty("chocolate")
	public void setChocolate(Integer chocolate) {
	this.chocolate = chocolate;
	}

	@JsonProperty("sugar")
	public Integer getSugar() {
	return sugar;
	}

	@JsonProperty("sugar")
	public void setSugar(Integer sugar) {
	this.sugar = sugar;
	}

	@JsonProperty("nTests")
	public Integer getNTests() {
	return nTests;
	}

	@JsonProperty("nTests")
	public void setnTests(Integer nTests) {
	this.nTests = nTests;
	}
}
