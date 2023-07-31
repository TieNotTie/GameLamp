#pragma once

namespace GameLamp {

	class BufferLayout;

	class VertexBuffer {
	public:
		virtual ~VertexBuffer() {}
	
		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual void setLayout(const BufferLayout& layout) = 0;
		virtual const BufferLayout& getLayout() const = 0;

		static VertexBuffer* create(float* vertices, uint32_t size);
	};

	class IndexBuffer {
	public:
		virtual ~IndexBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual uint32_t getCount() const = 0;

		static IndexBuffer* create(uint32_t* indices, uint32_t size);
	};

	enum class ShaderDataType : uint8_t
	{
		None = 0,
		Bool,
		Int, Int2, Int3, Int4,
		Float, Float2, Float3, Float4,
		Mat3, Mat4,
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
			case ShaderDataType::Bool:	 return 1;
			case ShaderDataType::Int:	 return 4;
			case ShaderDataType::Int2:	 return 4 * 2;
			case ShaderDataType::Int3:	 return 4 * 3;
			case ShaderDataType::Int4:	 return 4 * 4;
			case ShaderDataType::Float:	 return 4;
			case ShaderDataType::Float2: return 4 * 2;
			case ShaderDataType::Float3: return 4 * 3;
			case ShaderDataType::Float4: return 4 * 4;
			case ShaderDataType::Mat3:	 return 4 * 3 * 3;
			case ShaderDataType::Mat4:	 return 4 * 4 * 4;
		}

		GL_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	struct BufferElement
	{
		ShaderDataType Type;
		std::string Name;
		uint32_t Offset;
		uint32_t Size;
		bool Normalized;
	
		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
			: Type(type), Name(name), Size(ShaderDataTypeSize(type)), Offset(0), Normalized(normalized)
		{
		}

		uint32_t getComponentCount() const 
		{
			switch (Type)
			{
			case ShaderDataType::Bool:	 return 1;
			case ShaderDataType::Int:	 return 1;
			case ShaderDataType::Int2:	 return 2;
			case ShaderDataType::Int3:	 return 3;
			case ShaderDataType::Int4:	 return 4;
			case ShaderDataType::Float:	 return 1;
			case ShaderDataType::Float2: return 2;
			case ShaderDataType::Float3: return 3;
			case ShaderDataType::Float4: return 4;
			case ShaderDataType::Mat3:	 return 3 * 3;
			case ShaderDataType::Mat4:	 return 4 * 4;
			}
		GL_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout() = default;
		BufferLayout(const std::initializer_list<BufferElement>& elements) 
			: m_Elements(elements)
		{
			calculateOffsetsAndStride();
		}
		inline const std::vector<BufferElement>& getElements() const { return m_Elements; }
		uint32_t getStride() const { return m_Stride; }

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferElement>::const_iterator  end() const { return m_Elements.end(); }


	private:
		void calculateOffsetsAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements) {
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}

	private:
		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride = 0;
	};
} // namespace GameLamp
