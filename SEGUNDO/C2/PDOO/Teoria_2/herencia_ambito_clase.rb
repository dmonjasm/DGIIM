
class Padre
	@instancia_clase="instancia_clase"

	def initialize(a)
		@numero=a
	end

	def self.getInstancia
		@instancia_clase
	end

	def self.setInstancia=pr
		@instancia_clase=pr
	end

	def instancia_clase
		Padre.getInstancia
	end

	def instancia_mod=pr
		Padre.setInstancia=pr
	end
end

hola = Padre.new(10)
puts hola.instancia_clase
hola.instancia_mod="hola"
puts hola.instancia_clase
